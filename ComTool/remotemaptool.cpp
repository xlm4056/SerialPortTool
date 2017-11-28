#include "remotemaptool.h"

RemoteMapTool::RemoteMapTool(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("远程映射");
    this->setWindowIcon(QIcon(":/image/remote.ico"));
    this->setFixedSize(350,250);
    CsTypeLabel=new QLabel("选择类型  :");                                   //类型： 服务器  客户端
    CsTypeCombox=new QComboBox;
    CsTypeCombox->setFixedSize(150,25);
    CsTypeCombox->addItem("本地主机");
    CsTypeCombox->addItem("远程主机");
    CsTypeCombox->setCurrentIndex(0);
    QHBoxLayout* h1=new QHBoxLayout;
    h1->addWidget(CsTypeLabel);
    h1->addWidget(CsTypeCombox);
    h1->addStretch();
    ServerIpLabel=new QLabel("本地主机ip:");
    ServerIpLineEdit=new QLineEdit;
    ServerIpLineEdit->setFixedSize(150,25);
    ServerIpLineEdit->setFont(QFont("Timers",10,QFont::Bold));
    //QLineEdit设置ip输入格式
    QRegExp rx("^((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)$");
    QRegExpValidator*m_IPValidator = new QRegExpValidator(rx, this);
    ServerIpLineEdit->setValidator(m_IPValidator);
    ServerIpLineEdit->setText("222.222.221.41");
    ServerIpLineEdit->setEnabled(false);
    StartAndStopBtn=new QPushButton("开  启");
    QHBoxLayout* h2=new QHBoxLayout;
    h2->addWidget(ServerIpLabel);
    h2->addWidget(ServerIpLineEdit);
    h2->addWidget(StartAndStopBtn);
    h2->addStretch();

    LogTextEdit=new QTextEdit;
    LogTextEdit->setReadOnly(true);
    StatueLabel=new QLabel("当前类型:");
    QHBoxLayout* h4=new QHBoxLayout;
    h4->addStretch();
    h4->addWidget(StatueLabel);

    QVBoxLayout* v=new QVBoxLayout;
    v->addLayout(h1);
    v->addLayout(h2);
    v->addWidget(LogTextEdit);
    v->addStretch();
    v->addLayout(h4);
    this->setLayout(v);
    inits();
    connectfunction();
}

RemoteMapTool::~RemoteMapTool()
{

}

void RemoteMapTool::inits()
{
    startflag=false;
    server=NULL;
    socket=NULL;
    LiveTimer=NULL;
    CntLiveTimer=NULL;
    cntlive=0;
}

void RemoteMapTool::connectfunction()
{
    connect(StartAndStopBtn,SIGNAL(clicked()),this,SLOT(StartAndStopBtnSlots()));
    connect(CsTypeCombox,SIGNAL(currentIndexChanged(int)),this,SLOT(currentIndexChangedSlots(int)));
}

void RemoteMapTool::currentIndexChangedSlots(int index)
{
    if(index==0)
    {
        ServerIpLineEdit->setEnabled(false);
    }
    else
    {
        ServerIpLineEdit->setEnabled(true);
    }
}

void RemoteMapTool::StartAndStopBtnSlots()
{
    if(!startflag)
    {
        if(CsTypeCombox->currentText()=="本地主机")                     //本地服务器模块
        {
            this->server=new QTcpServer(this);
            connect(server,SIGNAL(newConnection()),this,SLOT(newconnectSlots()));
            server->listen(QHostAddress::AnyIPv4,9999);
            this->StatueLabel->setText("当前类型:本地主机开启成功");
        }
        else if(CsTypeCombox->currentText()=="远程主机")                //远程客户端模块
        {
            QString ipstr=this->ServerIpLineEdit->text();
            if(ipstr=="")
            {
                QMessageBox msgBox;
                msgBox.setWindowTitle("提示");
                msgBox.setWindowIcon(QIcon(":/image/remote.ico"));
                msgBox.setText("服务器ip不能为空.");
                msgBox.exec();
                return ;
            }
            this->socket=new QTcpSocket(this);
            this->socket->setReadBufferSize(0);                   //设置发送缓存大小
            socket->connectToHost(ipstr.toStdString().c_str(),9999);
            connect(socket,SIGNAL(connected()),this,SLOT(connectSlots()));
        }
        StartAndStopBtn->setText("关  闭");
        startflag=true;
    }
    else                                            //界面点击断开按钮
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, tr("提示"),\
                                      "确认是否关闭？",
                                      QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
        }
        else if (reply == QMessageBox::No)
        {
            return ;
        }
        if(server!=NULL)
        {
            delete server;
            server=NULL;
        }
        if(socket!=NULL)
        {
            delete socket;
            socket=NULL;
        }
        StartAndStopBtn->setText("开  启");
        startflag=false;
        if(LiveTimer!=NULL)
        {
            LiveTimer->disconnect();
            delete LiveTimer;
            LiveTimer=NULL;
        }
        cntlive=0;
        if(CntLiveTimer!=NULL)
        {
            CntLiveTimer->disconnect();
            delete CntLiveTimer;
            CntLiveTimer=NULL;
        }
    }
}

void RemoteMapTool::newconnectSlots()
{
    if(socket!=NULL)
    {
        delete socket;
        socket=NULL;
    }
    socket=server->nextPendingConnection();
    socket->setReadBufferSize(0);
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyreadSlots()));
    this->socket->write("welcome to server.");                            //向客户端发送欢迎信息
    CntLiveTimer=new QTimer(this);
    connect(CntLiveTimer,SIGNAL(timeout()),this,SLOT(CntLiveTimerSlots()));
    CntLiveTimer->start(4000);
    LogTextEdit->append("一个客户端来连接了....");
}

void RemoteMapTool::readyreadSlots()
{
    QByteArray data;
    data.clear();
    if(socket!=NULL)
    {
        data.append(socket->readAll());
    }
    //解析客户端发送过来的数据
    ServerModeParsed(data);
}

void RemoteMapTool::ServerModeParsed(QByteArray data)
{
    if(data.contains("Keep Alive"))
    {
        cntlive=0;
        return ;
    }
    if(data.contains("ready ok"))
    {
        emit RemoteMapToolOpenSignal(1);
    }
    if(data.contains("SetMsg"))
    {
        emit RemoteMapToolSetSignal(data);
    }

    if(data.contains("SendData"))
    {
        emit clientRecvDataSignal(data);
    }
    if(data.contains("SetRecvType"))
    {
        emit RecvTypeChangeSignals(data);
    }
    if(data.contains("SetSendType"))
    {
        emit SendTypeChangeSignals(data);   //SetSendType&HEX
    }
    if(data.contains("closeport"))
    {
        emit ReadCloseSignal();             //告诉主窗口该清理资源了
    }
}

void RemoteMapTool::SaidRemoteConOkSlots(int param)
{
    if(this->socket!=NULL)
    {
        QByteArray data;
        if(param==1)
        {
            data="Connect Ok";
        }
        else
        {
            data="Connect No";
        }
        this->socket->write(data);
    }
}
void RemoteMapTool::sendComInfoSlots(QByteArray info)
{
    if(this->socket!=NULL)
    {
        this->socket->write(info);
    }
}

/***********************************************************************/
/***************************客户端处理槽函数******************************/
/***********************************************************************/
void RemoteMapTool::connectSlots()
{
    connect(socket,SIGNAL(readyRead()),this,SLOT(SocketreadyReadSlots()));
    this->StatueLabel->setText("当前类型:远程主机开启成功");
    LiveTimer=new QTimer(this);
    connect(LiveTimer,SIGNAL(timeout()),this,SLOT(KeepLiveSlots()));
    LiveTimer->start(4000);
}

void RemoteMapTool::SocketreadyReadSlots()
{
    QByteArray data;
    data.clear();

    while(!socket->bytesAvailable())
    {
        QThread::usleep(20);
    }
    //这里的解析数据
    SocketModeParsed(socket->readAll());
}

void RemoteMapTool::SocketModeParsed(QByteArray data)                  //远程解析数据
{
    if(data=="welcome to server.")
    {
        LogTextEdit->append(data);
        QByteArray replystr="ready ok";
        this->socket->write(replystr);

        emit RemoteMapToolOpenSignal(2);
        return ;
    }
    if(data.contains("ComInfo"))
    {
        LogTextEdit->append(data);
        emit CominfoSignal(data);
    }
    if(data.contains("Not Com"))
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("提示");
        msgBox.setWindowIcon(QIcon(":/image/com.ico"));
        msgBox.setText("本地主机没有串口可用.");
        msgBox.exec();
    }
    if(data.contains("Connect Ok"))
    {
        emit clientConnectOkSignal(1);
    }
    else if(data.contains("Connect No"))
    {
        emit clientConnectOkSignal(0);
    }
    if(data.contains("RecvData"))
    {
        emit clientRecvDataRealSignal(data);
    }
    if(data.contains("CloseOk"))
    {
        emit closeoksignal();
    }
}

void RemoteMapTool::KeepLiveSlots()
{
    if(this->socket!=NULL)
    {
        QByteArray data;
        data="Keep Alive";
        this->socket->write(data);
    }
}

void RemoteMapTool::CntLiveTimerSlots()
{
    ++cntlive;
    if(cntlive>7)
    {
        //客户端已经断开了连接
        if(socket!=NULL)
        {
            delete socket;
            socket=NULL;
        }
        cntlive=0;
        if(CntLiveTimer!=NULL)
        {
            CntLiveTimer->disconnect();
            delete CntLiveTimer;
            CntLiveTimer=NULL;
        }
    }
}

void RemoteMapTool::LocalCloseOkSlots()
{
   if(this->socket!=NULL)
   {
       QByteArray data;
       data="CloseOk";
       this->socket->write(data);
   }
}
void RemoteMapTool::setInfoSlots(QByteArray setMsg)
{
    if(this->socket!=NULL)
    {
        this->socket->write(setMsg);
    }
}

void RemoteMapTool::clientSendDataSlots(QByteArray data)
{
    if(this->socket!=NULL)
    {
        this->socket->write(data);
    }
}

void RemoteMapTool::LocalRecvDataSlots(QByteArray data)
{
    if(this->socket!=NULL)
    {
        this->socket->write(data);
        this->socket->flush();
    }
}

void RemoteMapTool::clientRecvTypeChangeSlots(bool param)
{
    QByteArray data;
    if(param)                                                                         //HEX
    {
        data="SetRecvType&HEX";
    }
    else                                                                              //ASCII
    {
        data="SetRecvType&ASCII";
    }
    if(this->socket!=NULL)
    {
        this->socket->write(data);
    }
}

void RemoteMapTool::closeSerialPortSlots()
{
    QByteArray data;
    data="closeport";
    if(this->socket!=NULL)
    {
        this->socket->write(data);
    }
}

void RemoteMapTool::closeEvent(QCloseEvent *)
{
    emit RemoteMapToolCloseSignal();
}
