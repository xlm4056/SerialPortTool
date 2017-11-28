#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowIcon(QIcon(":/image/com.ico"));
    this->setWindowTitle("串口调试");
    this->setMinimumWidth(900);
    /*********************************************/
    ComGrpBox=new QGroupBox;
    ComGrpBox->setTitle("串口设置");
    ComLabel=new QLabel(" 串 口");
    ComBox=new QComboBox;
    QHBoxLayout* ch1=new QHBoxLayout;
    ch1->addWidget(ComLabel);
    ch1->addWidget(ComBox);
    BaudRateLabel=new QLabel(" 波 特 率");                            //波特率
    BaudRateBox=new QComboBox;
    QHBoxLayout* ch2=new QHBoxLayout;
    ch2->addWidget(BaudRateLabel);
    ch2->addWidget(BaudRateBox);
    DataBitLabel=new QLabel(" 数 据 位");                             //数据位
    DataBitBox=new QComboBox;
    DataBitBox->addItem("CS8");
    DataBitBox->addItem("CS7");
    DataBitBox->addItem("CS6");
    DataBitBox->addItem("CS5");
    DataBitBox->setCurrentIndex(0);
    QHBoxLayout* ch3=new QHBoxLayout;
    ch3->addWidget(DataBitLabel);
    ch3->addWidget(DataBitBox);
    CheckBitLabel=new QLabel(" 校 验 位");                            //校验位
    CheckBitBox=new QComboBox;
    CheckBitBox->addItem("None");
    CheckBitBox->addItem("奇校验");
    CheckBitBox->addItem("偶校验");
    CheckBitBox->addItem("空格校验");
    CheckBitBox->setCurrentIndex(0);
    QHBoxLayout* ch4=new QHBoxLayout;
    ch4->addWidget(CheckBitLabel);
    ch4->addWidget(CheckBitBox);
    StopBitLabel=new QLabel(" 停 止 位");                             //停止位
    StopBitBox=new QComboBox;
    StopBitBox->addItem("1 Byte");
    StopBitBox->addItem("1.5 Byte");
    StopBitBox->addItem("2 Byte");
    StopBitBox->setCurrentIndex(0);
    QHBoxLayout* ch5=new QHBoxLayout;
    ch5->addWidget(StopBitLabel);
    ch5->addWidget(StopBitBox);
    FlowCtlLabel=new QLabel(" 流 控");                             //流控
    FlowCtlBox=new QComboBox;
    FlowCtlBox->addItem("None");
    FlowCtlBox->addItem("硬件流控");
    FlowCtlBox->addItem("软件流控");
    FlowCtlBox->setCurrentIndex(0);
    QHBoxLayout* ch6=new QHBoxLayout;
    ch6->addWidget(FlowCtlLabel);
    ch6->addWidget(FlowCtlBox);
    QVBoxLayout* cv1=new QVBoxLayout;
    cv1->addLayout(ch1);
    cv1->addLayout(ch2);
    cv1->addLayout(ch3);
    cv1->addLayout(ch4);
    cv1->addLayout(ch5);
    cv1->addLayout(ch6);
    ComGrpBox->setLayout(cv1);

    ReadGrpBox=new QGroupBox;
    ReadGrpBox->setTitle("接收设置");
    RAsciiRadioBtn=new QRadioButton("ASCII");
    RHexRadioBtn=new QRadioButton("HEX");
    RHexRadioBtn->setChecked(true);
    QHBoxLayout* rh1=new QHBoxLayout;
    rh1->addWidget(RAsciiRadioBtn);
    rh1->addWidget(RHexRadioBtn);
    AutoChgeLineBtn=new QCheckBox("自动换行");                         //自动换行
    AutoChgeLineBtn->setChecked(true);
    ConnectComBtn=new QPushButton("连接串口");

    QHBoxLayout* rh2=new QHBoxLayout;
    rh2->addWidget(AutoChgeLineBtn);
    rh2->addWidget(ConnectComBtn);
    ShowSendDataBtn=new QCheckBox("显示发送");                         //显示发送
    StopAndContinRecvBtn=new QPushButton("暂停接收");

    QHBoxLayout* rh3=new QHBoxLayout;
    rh3->addWidget(ShowSendDataBtn);
    rh3->addWidget(StopAndContinRecvBtn);
    ShowLocalTimeBtn=new QCheckBox("显示时间");                        //显示时间
    ShowLocalTimeBtn->setChecked(true);
    ShowSendDataBtn->setChecked(false);

    ClearReadBtn=new QPushButton("读数清空");
    QHBoxLayout* rh4=new QHBoxLayout;
    rh4->addWidget(ShowLocalTimeBtn);
    rh4->addWidget(ClearReadBtn);
    QVBoxLayout* rv1=new QVBoxLayout;
    rv1->addLayout(rh1);
    rv1->addLayout(rh2);
    rv1->addLayout(rh4);
    rv1->addLayout(rh3);
    ReadGrpBox->setLayout(rv1);

    SendGrpBox=new QGroupBox;
    SendGrpBox->setTitle("发送设置");
    SAsciiRadioBtn=new QRadioButton("ASCII");
    SAsciiRadioBtn->setChecked(true);
    SHexRadioBtn=new QRadioButton("HEX");
    QHBoxLayout* sh1=new QHBoxLayout;
    sh1->addWidget(SAsciiRadioBtn);
    sh1->addWidget(SHexRadioBtn);
    ReSendBtn=new QCheckBox("重复发送");
    ReSendSpinBox=new QSpinBox;
    ReSendSpinBox->setRange(10,15000);
    ReSendSpinBox->setSingleStep(10);
    ReSendSuffixLabel=new QLabel("ms");
    QHBoxLayout* sh2=new QHBoxLayout;
    sh2->addWidget(ReSendBtn);
    sh2->addWidget(ReSendSpinBox);
    sh2->addWidget(ReSendSuffixLabel);
    RecvRateBtn=new QCheckBox("接收频率");                           //接收频率
    RecvRateSpinBox=new QSpinBox;
    RecvRateSpinBox->setRange(10,15000);
    RecvRateSuffixLabel=new QLabel("ms");
    QHBoxLayout* sh3=new QHBoxLayout;
    sh3->addWidget(RecvRateBtn);
    sh3->addWidget(RecvRateSpinBox);
    sh3->addWidget(RecvRateSuffixLabel);
    QVBoxLayout* sv1=new QVBoxLayout;
    sv1->addLayout(sh1);
    sv1->addLayout(sh2);
    sv1->addLayout(sh3);
    SendGrpBox->setLayout(sv1);

    ToolGrpBox=new QGroupBox;                                         //工具箱
    ToolGrpBox->setTitle("工具箱");
    CrcToolBtn=new QPushButton("CRC 计 算");                           //Crc
    CalcToolBtn=new QPushButton("计 算 器");                           //Calc
    NoteToolBtn=new QPushButton("笔 记 本");                           //笔记
    RemoteMapBtn=new QPushButton("远 程 映 射");
    HelpInfoBtn=new QPushButton("帮 助 信 息");
    QVBoxLayout* tv1=new QVBoxLayout;
    tv1->addWidget(CrcToolBtn);
    tv1->addWidget(CalcToolBtn);
    tv1->addWidget(NoteToolBtn);
    tv1->addWidget(RemoteMapBtn);
    tv1->addWidget(HelpInfoBtn);
    ToolGrpBox->setLayout(tv1);

    ReadTextEdit=new QTextEdit;                                     //接受区域
    ReadTextEdit->setPlaceholderText("接收区域");
    ReadTextEdit->setReadOnly(true);
    ReadTextEdit->setStyleSheet("color:brown");
    ReadTextEdit->setFont(QFont("Timers",10,QFont::Bold));
    SendLineEdit=new QLineEdit;                                     //发送区域
    SendLineEdit->setPlaceholderText("请输入发送内容,回车发送附带回车符");
    SendLineEdit->setMaximumHeight(60);
    SendLineEdit->setFont(QFont("Timers",10,QFont::Bold));
    SubmitBtn=new QPushButton("发送");
    SubmitBtn->setFixedSize(60,60);
    QHBoxLayout* h1=new QHBoxLayout;
    h1->addWidget(SendLineEdit);
    h1->addWidget(SubmitBtn);
    TxLabel=new QLabel("|Tx:");
    TxValLabel=new QLabel;
    TxValLabel->setStyleSheet("color:green");
    TxValLabel->setText("0");
    TxValLabel->setMinimumWidth(80);
    TxValSuffixLabel=new QLabel("Bytes");
    SxLabel=new QLabel("|Sx:");
    SxValLabel=new QLabel;
    SxValLabel->setStyleSheet("color:green");
    SxValLabel->setText("0");
    SxValLabel->setMinimumWidth(80);
    SxValSuffixLabel=new QLabel("Bytes");
    StartTimeLabel=new QLabel;
    QDateTime curtime=QDateTime::currentDateTime();
    QString curtimeStr=curtime.toString("        软件启动时间: yyyy-MM-hh:mm:ss  软件版本: v1.2  ");
    StartTimeLabel->setText(curtimeStr);
    curStateLabel=new QLabel("未连接");
    SendFileBtn=new QPushButton("下载文件");
    OutPutBtn=new QPushButton("导出数据");
    QHBoxLayout* h3=new QHBoxLayout;
    h3->addWidget(TxLabel);
    h3->addWidget(TxValLabel);
    h3->addWidget(TxValSuffixLabel);
    h3->addWidget(SxLabel);
    h3->addWidget(SxValLabel);
    h3->addWidget(SxValSuffixLabel);
    h3->addWidget(StartTimeLabel);
    h3->addWidget(curStateLabel);
    h3->addStretch();
    h3->addWidget(SendFileBtn);
    h3->addWidget(OutPutBtn);

    QVBoxLayout* v1=new QVBoxLayout;
    v1->addWidget(ReadTextEdit);
    v1->addLayout(h1);

    QVBoxLayout* v2=new QVBoxLayout;
    v2->addWidget(ComGrpBox);
    v2->addWidget(ReadGrpBox);
    v2->addWidget(SendGrpBox);
    v2->addWidget(ToolGrpBox);

    QHBoxLayout* h2=new QHBoxLayout;
    h2->addLayout(v2);
    h2->addLayout(v1);
    QVBoxLayout* v=new QVBoxLayout;
    v->addLayout(h2);
    v->addLayout(h3);
    this->setLayout(v);
    init();
}

Widget::~Widget()
{

}

void Widget::init()
{
    sendcnt=0;                                //发送计数
    recvcnt=0;
    rsendtimer=NULL;
    SerialPort=NULL;
    comconflag=false;
    sendtype=false;                                        //false ascii true hex
    recvtype=true;
    resendrate=10;
    showcurtimeflag=true;
    showsendflag=false;
    recvflag=false;                                        //接收标记  false 不按频率接收 true 按频率接收
    recvrate=10;
    recvstopflag=false;
    helpobj=NULL;
    crcobj=NULL;
    outputobj=NULL;
    noteobj=NULL;
    RemoteMapObj=NULL;
    resendflag=false;
    ReadTextFontSize=10;
    sameflag=false;
    for(int i=0;i<10;++i)
    {
        historycmdlist[i]=" ";
    }
    bkimage.load(":/image/bkg.jpg");
    curindex=0;
    insertindex=0;
    remoteType=0;
    ReadLoalComDevice();
    initBaudRate();
    connectfunction();
}

void Widget::connectfunction()
{
    //绑定快捷键
    QShortcut* sendkey=new QShortcut(QKeySequence(Qt::Key_Return),this);
    QShortcut* UpKey=new QShortcut(QKeySequence(Qt::Key_Up),this);
    QShortcut* DownKey=new QShortcut(QKeySequence(Qt::Key_Down),this);
    connect(UpKey,SIGNAL(activated()),this,SLOT(UpKeyClickedSlots()));
    connect(DownKey,SIGNAL(activated()),this,SLOT(DownKeyClickedSlots()));
    connect(sendkey,SIGNAL(activated()),this,SLOT(EnterSendSlots()));
    connect(StopAndContinRecvBtn,SIGNAL(clicked()),this,SLOT(StopAndContinRecvBtnSlots()));
    connect(RAsciiRadioBtn,SIGNAL(clicked()),this,SLOT(RAsciiRadioBtnSlots()));
    connect(RHexRadioBtn,SIGNAL(clicked()),this,SLOT(RHexRadioBtnSlots()));
    connect(SAsciiRadioBtn,SIGNAL(clicked()),this,SLOT(SAsciiRadioBtnSlots()));
    connect(SHexRadioBtn,SIGNAL(clicked()),this,SLOT(SHexRadioBtnSlots()));
    connect(SubmitBtn,SIGNAL(clicked()),this,SLOT(SubmitBtnSlots()));
    connect(ClearReadBtn,SIGNAL(clicked()),this,SLOT(ClearReadBtnSlots()));
    connect(ConnectComBtn,SIGNAL(clicked()),this,SLOT(ConnectComBtnSlots()));
    connect(ReSendBtn,SIGNAL(stateChanged(int)),this,SLOT(ReSendStateChangedSlots(int)));
    connect(ReSendSpinBox,SIGNAL(valueChanged(int)),this,SLOT(ReSendSpinValChangeSlots(int)));
    connect(RecvRateBtn,SIGNAL(stateChanged(int)),this,SLOT(RecvRateBtnSlots(int)));
    connect(RecvRateSpinBox,SIGNAL(valueChanged(int)),this,SLOT(RecvRateSpinValChangeSlots(int)));
    connect(ComBox,SIGNAL(currentIndexChanged(int)),this,SLOT(currentIndexChangedSlots(int)));
    connect(ShowLocalTimeBtn,SIGNAL(stateChanged(int)),this,SLOT(ShowLocalTimeBtnSlots(int)));
    connect(ShowSendDataBtn,SIGNAL(stateChanged(int)),this,SLOT(ShowSendDataBtnSlots(int)));
    connect(CrcToolBtn,SIGNAL(clicked()),this,SLOT(CrcToolBtnSlots()));
    connect(CalcToolBtn,SIGNAL(clicked()),this,SLOT(CalcToolBtnSlots()));
    connect(NoteToolBtn,SIGNAL(clicked()),this,SLOT(NoteToolBtnSlots()));
    connect(HelpInfoBtn,SIGNAL(clicked()),this,SLOT(HelpInfoBtnSlots()));
    connect(OutPutBtn,SIGNAL(clicked()),this,SLOT(OutPutBtnSlots()));
    connect(RemoteMapBtn,SIGNAL(clicked()),this,SLOT(RemoteMapBtnSlots()));
    connect(SendFileBtn,SIGNAL(clicked()),this,SLOT(SendFileBtnSlots()));
}

QByteArray Widget::HexStrToByteArray(QString str)
{
    QByteArray senddata;
    int hexdata,lowhexdata;
    int hexdatalen = 0;
    int len = str.length();
    senddata.resize(len/2);
    char lstr,hstr;
    for(int i=0; i<len; )
    {
        hstr=str[i].toLatin1();
        if(hstr == ' ')
        {
            i++;
            continue;
        }
        i++;
        if(i >= len)
            break;
        lstr = str[i].toLatin1();
        hexdata = ConvertHexChar(hstr);
        lowhexdata = ConvertHexChar(lstr);
        if((hexdata == 16) || (lowhexdata == 16))
            break;
        else
            hexdata = hexdata*16+lowhexdata;
        i++;
        senddata[hexdatalen] =hexdata;
        hexdatalen++;
    }
    senddata.resize(hexdatalen);
    return senddata;
}

char Widget::ConvertHexChar(char ch)
{
    if((ch >= '0') && (ch <= '9'))
    {
        return ch-0x30;
    }
    else if((ch >= 'A') && (ch <= 'F'))
    {
        return ch-'A'+10;
    }
    else if((ch >= 'a') && (ch <= 'f'))
    {
        return ch-'a'+10;
    }
    else return (-1);
}

QString Widget::ByteArrayToHexStr(QByteArray data)
{
    QString temp="";
    QString hex=data.toHex();
    for(int i=0;i<hex.length();i+=2)
    {
        temp+=hex.mid(i,2)+" ";
    }
    temp+=" ";
    return temp.trimmed().toUpper();
}

void Widget::initBaudRate()
{
    this->BaudRateBox->addItem("115200");
    this->BaudRateBox->addItem("57600");
    this->BaudRateBox->addItem("38400");
    this->BaudRateBox->addItem("19200");
    this->BaudRateBox->addItem("9600");
    this->BaudRateBox->addItem("4800");
    this->BaudRateBox->addItem("2400");
    this->BaudRateBox->addItem("1200");
    this->BaudRateBox->setCurrentIndex(4);
}

void Widget::ReadLoalComDevice()
{
    SerialInfo=new QSerialPortInfo();
    SerialList=SerialInfo->availablePorts();
    nSerialNum=SerialList.length();
    if(nSerialNum==0)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("提示");
        msgBox.setWindowIcon(QIcon(":/image/com.ico"));
        msgBox.setText("本电脑没有可用的串口设备.");
        msgBox.exec();
        return ;
    }
    for(unsigned i=0;i<nSerialNum;++i)
    {
        QString SerialName=SerialList[i].portName();
        QString SerialDesp=SerialList[i].description();                                      //串口设备的描述信息
        this->ComBox->addItem(QIcon(":/image/com.ico"),SerialName);
    }
    this->ComBox->setCurrentIndex(0);
    QString msg;
    msg="\n\n\t串口信息："+this->SerialList[0].description();
    this->ReadTextEdit->setText(msg);
}

void Widget::setBaudRate()
{
    if(remoteType==0)
    {
        curbaudstr=this->BaudRateBox->currentText();
    }
    if(curbaudstr=="115200")
    {
        this->SerialPort->setBaudRate(QSerialPort::Baud115200);
    }
    else if(curbaudstr=="57600")
    {
        this->SerialPort->setBaudRate(QSerialPort::Baud57600);
    }
    else if(curbaudstr=="38400")
    {
        this->SerialPort->setBaudRate(QSerialPort::Baud38400);
    }
    else if(curbaudstr=="19200")
    {
        this->SerialPort->setBaudRate(QSerialPort::Baud19200);
    }
    else if(curbaudstr=="9600")
    {
        this->SerialPort->setBaudRate(QSerialPort::Baud9600);
    }
    else if(curbaudstr=="4800")
    {
        this->SerialPort->setBaudRate(QSerialPort::Baud4800);
    }
    else if(curbaudstr=="2400")
    {
        this->SerialPort->setBaudRate(QSerialPort::Baud2400);
    }
    else if(curbaudstr=="1200")
    {
        this->SerialPort->setBaudRate(QSerialPort::Baud1200);
    }
}

void Widget::setDataBit()
{
    if(remoteType==0)
    {
        curdatabitstr=this->DataBitBox->currentText();
    }
    if(curdatabitstr=="CS8")
    {
        this->SerialPort->setDataBits(QSerialPort::Data8);
    }
    else if(curdatabitstr=="CS7")
    {
        this->SerialPort->setDataBits(QSerialPort::Data7);
    }
    else if(curdatabitstr=="CS6")
    {
        this->SerialPort->setDataBits(QSerialPort::Data6);
    }
    else if(curdatabitstr=="CS5")
    {
        this->SerialPort->setDataBits(QSerialPort::Data5);
    }
}

void Widget::setStopBit()
{
    if(remoteType==0)
    {
        curstopbitstr=this->StopBitBox->currentText();
    }
    if(curstopbitstr=="2 Byte")
    {
        this->SerialPort->setStopBits(QSerialPort::TwoStop);
    }
    else if(curstopbitstr=="1 Byte")
    {
        this->SerialPort->setStopBits(QSerialPort::OneStop);
    }
    else if(curstopbitstr=="1.5 Byte")
    {
        this->SerialPort->setStopBits(QSerialPort::OneAndHalfStop);
    }
}

void Widget::setParityBit()
{
    if(remoteType==0)
    {
        curParitystr=this->CheckBitBox->currentText();
    }
    if(curParitystr=="None")
    {
        this->SerialPort->setParity(QSerialPort::NoParity);
    }
    else if(curParitystr=="奇校验")
    {
        this->SerialPort->setParity(QSerialPort::OddParity);
    }
    else if(curParitystr=="偶校验")
    {
        this->SerialPort->setParity(QSerialPort::EvenParity);
    }
    else if(curParitystr=="空格校验")
    {
        this->SerialPort->setParity(QSerialPort::SpaceParity);
    }
}

void Widget::setFlowControl()
{
    if(remoteType==0)
    {
        curflowStr=this->FlowCtlBox->currentText();
    }
    if(curflowStr=="None")
    {
        this->SerialPort->setFlowControl(QSerialPort::NoFlowControl);
    }
    else if(curflowStr=="硬件流控")
    {
        this->SerialPort->setFlowControl(QSerialPort::HardwareControl);
    }
    else if(curflowStr=="软件流控")
    {
        this->SerialPort->setFlowControl(QSerialPort::SoftwareControl);
    }
}

QString Widget::getValueContent(QSerialPort::SerialPortError errorIndex)
{
    QString errorContent;
    switch(errorValue)
    {
    case 0:
        errorContent="No Error";break;
    case 1:
        errorContent="Device Not Found";break;
    case 2:
        errorContent="Permission Error";break;
    case 3:
        errorContent="Open Error";break;
    case 4:
        errorContent="Not Open Error";break;
    case 5:
        errorContent="Parity Error";break;
    case 6:
        errorContent="Framing Error";break;
    case 7:
        errorContent="Break Condition Error";break;
    case 8:
        errorContent="Write Error";break;
    case 9:
        errorContent="Read Error";break;
    case 10:
        errorContent="Resource Error";break;
    case 11:
        errorContent="Unsupported Operation Error";break;
    case 12:
        errorContent="Time Out Error";break;
    case 13:
        errorContent="No Data Received";break;
    case 14:
        errorContent="Please Open Serial Port First";break;
    case 15:
        errorContent="Set BaudRate Failed";break;
    default:
        errorContent="No error";
    }
    return errorContent;
}

void Widget::showErrorMsg(QSerialPort::SerialPortError errorEum)
{
    if(showcurtimeflag)
    {
        errorInfo=" ";
        currentTime=QDateTime::currentDateTime();
        timeinfo=currentTime.toString("yyyy-MM-d hh:mm:ss");
        errorInfo=QString::fromLocal8Bit("错误提示信息   ");
        errorInfo+=timeinfo;
        errorInfo+="\n";
    }
    else
    {
        errorInfo=" ";
        errorInfo=QString::fromLocal8Bit("错误提示信息   ");
        errorInfo+="\n";
    }
    this->ReadTextEdit->append(errorInfo+getValueContent(errorEum));
}

void Widget::showRecvMsg(QString recvStr)
{
    QString showReciveMsg;
    if(sameflag)
    {
        showReciveMsg+=recvStr;
    }
    else
    {
        showReciveMsg+=recvStr+" ";
    }
    this->ReadTextEdit->insertPlainText(showReciveMsg);                          //不换行添加内容
    this->ReadTextEdit->moveCursor(QTextCursor::End);
}

void Widget::showSendMsg(QByteArray sendArray)
{
    if(!showsendflag)   return;
    QString showSendMsg;
    if(showcurtimeflag)
    {

        currentTime=QDateTime::currentDateTime();
        timeinfo=currentTime.toString("yyyy-MM-d hh:mm:ss");
        showSendMsg+=QString::fromLocal8Bit("发送数据 : ");
        showSendMsg+=timeinfo;
        showSendMsg+="\n";
        //判断显示16进制还是ACSII字符
        if(recvflag)
            showSendMsg+=ByteArrayToHexStr(sendArray);
        else
            showSendMsg+=sendArray;
    }
    else
    {
        showSendMsg=QString::fromLocal8Bit("发送数据 : ");
        if(recvflag)
            showSendMsg+=ByteArrayToHexStr(sendArray);
        else
            showSendMsg+=sendArray;
    }
    this->ReadTextEdit->append(showSendMsg);
}

void Widget::ClearReadBtnSlots()
{
    this->ReadTextEdit->clear();
    this->update();
}

void Widget::ConnectComBtnSlots()
{
    if(!comconflag)
    {
        if(remoteType==0)
        {
            if(SerialPort!=NULL)
            {
                SerialPort->close();
                SerialPort=NULL;
            }
            SerialPort=new QSerialPort(SerialList[ComBox->currentIndex()].portName());
            if(!SerialPort)
            {
                QSerialPort::SerialPortError errorVal=SerialPort->error();
                QMessageBox msgBox;
                msgBox.setWindowTitle("提示");
                msgBox.setWindowIcon(QIcon(":/image/com.ico"));
                msgBox.setText("初始化串口设备失败.");
                msgBox.exec();
                return ;
            }
            if(!SerialPort->open(QIODevice::ReadWrite))
            {
                QMessageBox msgBox;
                msgBox.setWindowTitle("提示");
                msgBox.setWindowIcon(QIcon(":/image/com.ico"));
                msgBox.setText("打开串口设备失败.");
                msgBox.exec();
                return ;
            }
            connect(SerialPort,SIGNAL(readyRead()),this,SLOT(OnReadyReadSlots()));
            setBaudRate();                                  //设置串口对象波特率
            setDataBit();                                   //设置串口对象数据位
            setStopBit();                                   //设置串口对象停止位
            setParityBit();                                 //设置串口对象奇偶校验位
            setFlowControl();                               //设置串口对象流控
            this->ReadTextEdit->clear();
            comconflag=true;
            ComBox->setEnabled(false);

            ConnectComBtn->setText("断开连接");
            QMessageBox msgBox;
            msgBox.setWindowTitle("提示");
            msgBox.setWindowIcon(QIcon(":/image/com.ico"));
            msgBox.setText("串口连接成功.");
            msgBox.exec();
            curStateLabel->setText("已连接");
        }
        else if(remoteType==2)
        {
            ComBox->setEnabled(false);
            QByteArray setMsg="SetMsg&";
            setMsg+=this->ComBox->currentText()+"#";
            setMsg+=this->BaudRateBox->currentText()+"#";
            setMsg+=this->DataBitBox->currentText()+"#";
            setMsg+=this->CheckBitBox->currentText()+"#";
            setMsg+=this->StopBitBox->currentText()+"#";
            setMsg+=this->FlowCtlBox->currentText()+"#";
            if(!recvtype)
            {
                setMsg+="ASCII#";
            }
            else
            {
                setMsg+="HEX#";
            }
            if(!sendtype)
            {
                setMsg+="ASCII#";
            }
            else
            {
                setMsg+="HEX#";
            }
            if(this->resendflag)
            {
                setMsg+="RYES#";
            }
            else
            {
                setMsg+="RNO@";
            }
            emit setInfoSignal(setMsg);
        }
    }
    else
    {
        //存储变量也要清理
        if(remoteType==0)
        {
            sendcnt=0;                                //发送计数
            recvcnt=0;
            comconflag=false;
            sendtype=false;                                        //false ascii true hex
            this->SAsciiRadioBtn->setChecked(true);
            recvtype=true;
            this->RHexRadioBtn->setChecked(true);
            resendrate=10;
            showcurtimeflag=true;
            this->ShowLocalTimeBtn->setChecked(true);
            showsendflag=false;
            this->ShowSendDataBtn->setChecked(false);
            recvflag=false;                                        //接收标记  false 不按频率接收 true 按频率接收
            recvrate=10;
            this->RecvRateBtn->setChecked(false);
            this->ReSendBtn->setChecked(false);
            comconflag=false;
            if(rsendtimer!=NULL)
                rsendtimer->disconnect();
            if(SerialPort!=NULL)
            {
                SerialPort->close();
                SerialPort=NULL;
            }
            ComBox->setEnabled(true);
            curStateLabel->setText("未连接");
            ConnectComBtn->setText("连接串口");
        }
        else if(remoteType==2)
        {
            emit closeSerialPortSignal();
        }
    }
}

void Widget::ReSendStateChangedSlots(int state)
{
    if(state)                 //选中
    {
        if(rsendtimer==NULL)
        {
            rsendtimer=new QTimer(this);
            rsendtimer->start(resendrate);
        }
        resendflag=true;
        rsendtimer->setInterval(resendrate);
        connect(rsendtimer,SIGNAL(timeout()),this,SLOT(timerresendTimeoutSlots()));
    }
    else
    {
        resendflag=false;
        rsendtimer->disconnect();
    }
}

void Widget::ReSendSpinValChangeSlots(int val)
{
    resendrate=val;
    if(rsendtimer!=NULL)
    {
        rsendtimer->setInterval(resendrate);
    }
}

void Widget::RecvRateBtnSlots(int state)
{
    if(state)                 //选中
    {
        recvflag=true;
    }
    else
    {
        recvflag=false;
    }
}

void Widget::RecvRateSpinValChangeSlots(int val)
{
    recvrate=val;
}

void Widget::OnReadyReadSlots()                                //串口有数据过来在这里处理
{
    if(this->SerialPort->bytesAvailable()<0)                   //判断缓存里面是否有数据可读
    {
        return ;
    }
    if(recvflag)                                               //按频率接收
    {
    }
    else
    {
        if(remoteType==0)
        {
            if(!recvstopflag)
            {
                QByteArray temp;
                temp=this->SerialPort->readAll();
                //qDebug()<<"recv:"<<temp;
                //转换格式
                QString recvMsg;
                if(recvtype)      //hex
                {
                    recvMsg=ByteArrayToHexStr(temp);
                }
                else              //ascii
                {
                    recvMsg=temp;
                }
                if(recvMsg.isEmpty())
                {
                    showErrorMsg((QSerialPort::SerialPortError)13);
                    return ;
                }
                ++recvcnt;
                QString recvcntstr=tr("%1").arg(recvcnt);
                TxValLabel->setText(recvcntstr);
                showRecvMsg(recvMsg);
            }
        }
        else if(remoteType==1)            //远程客户端
        {
            QByteArray temp;
            temp=this->SerialPort->readAll();
            //            qDebug()<<"recv:"<<temp;
            //转换格式
            QString recvMsg;
            if(recvtype)      //hex
            {
                recvMsg=ByteArrayToHexStr(temp);
            }
            else              //ascii
            {
                recvMsg=temp;
            }
            if(recvMsg.isEmpty())
            {
                return ;
            }
            //发送数据到远程
            QByteArray data="RecvData&"+recvMsg.toLatin1();
            data+="$";
            emit LocalRecvDataSignal(data);
        }
    }
}

void Widget::SubmitBtnSlots()                                   //发送按钮处理事件
{
    if(!comconflag&&remoteType==2)
    {
        return ;
    }
    if(remoteType==0)
    {
        if(!comconflag)
        {
            if(SerialPort!=NULL)
            {
                SerialPort->close();
                SerialPort=NULL;
            }
            SerialPort=new QSerialPort(SerialList[ComBox->currentIndex()].portName());
            if(!SerialPort)
            {
                QSerialPort::SerialPortError errorVal=SerialPort->error();
                QMessageBox msgBox;
                msgBox.setWindowTitle("提示");
                msgBox.setWindowIcon(QIcon(":/image/com.ico"));
                msgBox.setText("初始化串口设备失败.");
                msgBox.exec();
                return ;
            }
            if(!SerialPort->open(QIODevice::ReadWrite))
            {
                QMessageBox msgBox;
                msgBox.setWindowTitle("提示");
                msgBox.setWindowIcon(QIcon(":/image/com.ico"));
                msgBox.setText("打开串口设备失败.");
                msgBox.exec();
                return ;
            }
            connect(SerialPort,SIGNAL(readyRead()),this,SLOT(OnReadyReadSlots()));
            setBaudRate();                                  //设置串口对象波特率
            setDataBit();                                   //设置串口对象数据位
            setStopBit();                                   //设置串口对象停止位
            setParityBit();                                 //设置串口对象奇偶校验位
            setFlowControl();                               //设置串口对象流控
            this->ReadTextEdit->clear();
            comconflag=true;
            ComBox->setEnabled(false);
            curStateLabel->setText("已连接");
            QPixmap pix1;
            pix1.load(":/image/cona.ico",0,Qt::AutoColor);
            ConnectComBtn->setIcon(QIcon(pix1));
            QMessageBox msgBox;
            msgBox.setWindowTitle("提示");
            msgBox.setWindowIcon(QIcon(":/image/com.ico"));
            msgBox.setText("串口连接成功.");
            msgBox.exec();
        }
    }
    /*************************************/
    QString sendMsg=SendLineEdit->text();
    if(sendMsg=="")
    {
        return ;
    }

    QByteArray temp=sendMsg.toLatin1();
    if(sendtype)                                         //HEX
    {
        temp=HexStrToByteArray(sendMsg);
    }
    qint64 sendNum;
    char * sendContent=temp.data();
    //    sendContent[temp.count()]=0x0D;                      //末尾加回车符
    if(remoteType==0)
    {
        if(showsendflag)
        {
            QString senddata="发送数据:"+temp+"\n";
            this->ReadTextEdit->append(senddata);
        }
        sendNum=SerialPort->write(sendContent,temp.count());
        if(sendNum==-1)
        {
            //发送失败
            errorValue=SerialPort->error();
            showErrorMsg(errorValue);
            return ;
        }
        SerialPort->flush();

        sendcnt++;
        QString sxvalstr=tr("%1").arg(sendcnt);
        this->SxValLabel->setText(sxvalstr);
    }
    else if(remoteType==2)
    {
        if(showsendflag)
        {
            QString senddata="发送数据:"+temp+"\n";
            this->ReadTextEdit->append(senddata);
        }
        QByteArray sendstr="SendData&Chick#"+temp;
        emit clientSendDataSignal(sendstr);
    }
}

void Widget::EnterSendSlots()
{
    if(!this->comconflag) return ;
    QString sendMsg=SendLineEdit->text();
    if(sendMsg=="")
    {
        return ;
    }
    QByteArray temp=sendMsg.toLatin1();
    if(sendtype)                                         //HEX
    {
        temp=HexStrToByteArray(sendMsg);
    }
    if(remoteType==0)
    {
        if(showsendflag)
        {
            QString senddata="发送数据:"+temp+"\n";
            this->ReadTextEdit->append(senddata);
        }
        qint64 sendNum;
        char * sendContent=temp.data();
        sendContent[temp.count()]=0x0D;                      //末尾加回车符
        sendNum=SerialPort->write(sendContent,temp.count()+1);
        if(sendNum==-1)
        {
            //发送失败
            errorValue=SerialPort->error();
            showErrorMsg(errorValue);
            return ;
        }
        SerialPort->flush();
    }
    else if(remoteType==2)                                    //回车符到本地添加
    {
        if(showsendflag)
        {
            QString senddata="发送数据:"+temp+"\n";
            this->ReadTextEdit->append(senddata);
        }
        QByteArray sendstr="SendData&Enter#"+temp;
        emit clientSendDataSignal(sendstr);
    }
    if(insertindex>9)
    {
        insertindex=0;
    }
    this->historycmdlist[insertindex]=sendMsg;
    curindex=insertindex;
    insertindex++;
    sendcnt++;
    QString sxvalstr=tr("%1").arg(sendcnt);
    this->SxValLabel->setText(sxvalstr);
}

void Widget::currentIndexChangedSlots(int _index)
{
    if(remoteType==0)
    {
        this->ReadTextEdit->clear();
        QString msg;
        msg="\n\n\t串口信息："+this->SerialList[_index].description();
        this->ReadTextEdit->setText(msg);
        this->update();
    }
    else if(remoteType==2)
    {
        this->ReadTextEdit->clear();
        QString msg;
        msg="\n\n\t串口信息："+this->cominfomap.value(this->ComBox->currentText());
        this->ReadTextEdit->setText(msg);
        this->update();
    }
}

void Widget::SAsciiRadioBtnSlots()
{
    if(remoteType==0)
    {
        sendtype=false;
    }
    else if(remoteType==2)
    {
        sendtype=false;
    }
}

void Widget::SHexRadioBtnSlots()
{
    if(remoteType==0)
    {
        sendtype=true;
    }
    else if(remoteType==2)
    {
        sendtype=true;
    }
}

void Widget::RAsciiRadioBtnSlots()
{
    if(remoteType==0)
    {
        recvtype=false;
    }
    else if(remoteType==2)
    {
        emit clientRecvTypeChangeSignal(false);
    }
}

void Widget::RHexRadioBtnSlots()
{
    if(remoteType==0)
    {
        recvtype=true;
    }
    else if(remoteType==2)
    {
        emit clientRecvTypeChangeSignal(true);
    }
}

void Widget::ShowLocalTimeBtnSlots(int state)
{
    if(state)                 //选中
    {
        this->showcurtimeflag=true;
    }
    else
    {
        this->showcurtimeflag=false;
    }
}

void Widget::ShowSendDataBtnSlots(int state)
{
    if(state)
    {
        showsendflag=true;
    }
    else
    {
        showsendflag=false;
    }
}

void Widget::showSendFormatWarnMsg()
{
    if(sendtype)
    {
        if(showcurtimeflag)
        {
            errorInfo=" ";
            currentTime=QDateTime::currentDateTime();
            timeinfo=currentTime.toString("yyyy-MM-d hh:mm:ss");
            errorInfo=QString::fromLocal8Bit("提示信息   ");
            errorInfo+=timeinfo;
            errorInfo+="\n";
        }
        else
        {
            errorInfo=" ";
            errorInfo=QString::fromLocal8Bit("提示信息   ");
            errorInfo+="\n";
        }
        this->ReadTextEdit->append(QString::fromLocal8Bit("当前选择为16进制发送，请输入偶数倍长度！"));
    }
}

void Widget::timerresendTimeoutSlots()
{
    if(!comconflag)    return ;
    QString sendMsg=SendLineEdit->text();
    if(sendMsg!="")
    {
        QString sendMsg=SendLineEdit->text();
        if(sendMsg=="")
        {
            return ;
        }
        QByteArray temp=sendMsg.toLatin1();
        if(sendtype)                                         //HEX
        {
            temp=HexStrToByteArray(sendMsg);
        }
        qint64 sendNum;
        char * sendContent=temp.data();
        sendContent[temp.count()]=0x0D;                      //末尾加回车符
        sendNum=SerialPort->write(sendContent,temp.count()+1);
        if(sendNum==-1)
        {
            //发送失败
            errorValue=SerialPort->error();
            showErrorMsg(errorValue);
            return ;
        }
        SerialPort->flush();
        sendcnt++;
        QString sxvalstr=tr("%1").arg(sendcnt);
        this->SxValLabel->setText(sxvalstr);
    }
}

void Widget::StopAndContinRecvBtnSlots()
{
    if(recvstopflag)
    {
        StopAndContinRecvBtn->setText("暂停接收");
    }
    else
    {
        StopAndContinRecvBtn->setText("继续接收");
    }
}

void Widget::CrcToolBtnSlots()
{
    if(crcobj!=NULL)
    {
        crcobj->hide();
        delete crcobj;
        crcobj=NULL;
    }
    crcobj=new CrcTool;
    connect(crcobj,SIGNAL(crctoolclosesignal()),this,SLOT(crctoolcloseSlots()));
    crcobj->show();
}

void Widget::CalcToolBtnSlots()
{
    QString calcPath="C://Windows//System32//calc.exe";
    QProcess::startDetached(calcPath);
}

void Widget::NoteToolBtnSlots()
{
    if(noteobj==NULL)
    {
        noteobj=new NoteTool;
    }
    connect(noteobj,SIGNAL(notetoolclosesignal()),this,SLOT(notetoolcloseSlots()));
    noteobj->show();
}

void Widget::HelpInfoBtnSlots()
{
    if(helpobj!=NULL)
    {
        delete helpobj;
        helpobj=NULL;
    }
    helpobj=new HelpInfo;
    connect(helpobj,SIGNAL(helpinfoclosesignal()),this,SLOT(helpinfocloseSlots()));
    helpobj->show();
}

void Widget::helpinfocloseSlots()
{
    if(helpobj!=NULL)
    {
        helpobj->hide();
        delete helpobj;
        helpobj=NULL;
    }
}

void Widget::crctoolcloseSlots()
{
    if(crcobj!=NULL)
    {
        crcobj->hide();
        delete crcobj;
        crcobj=NULL;
    }
}

void Widget::OutPutBtnSlots()
{
    //开一个线程进行导出操作
    QString recvstr=this->ReadTextEdit->toPlainText();
    if(recvstr=="")
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("提示");
        msgBox.setWindowIcon(QIcon(":/image/com.ico"));
        msgBox.setText("当前读取的数据区域没有数据.");
        msgBox.exec();
        return ;
    }
    //弹出一个路径选择框
    QString filename = QFileDialog::getSaveFileName(this,tr("Save Name"),"",tr("*.txt")); //选择路径
    if(filename.isEmpty())
        return;
    if(outputobj!=NULL)
    {
        delete outputobj;
        outputobj=NULL;
    }
    outputobj=new OutPutThread;
    connect(outputobj,SIGNAL(outputfinishedsignal()),this,SLOT(outputfinishedSlots()));
    outputobj->settypeflag(1);
    outputobj->setfilepath(filename);
    outputobj->setReadTextEdit(ReadTextEdit);
    outputobj->start();
}

void Widget::outputfinishedSlots()
{
    if(outputobj!=NULL)
    {
        delete outputobj;
        outputobj=NULL;
    }
    QMessageBox msgBox;
    msgBox.setWindowTitle("提示");
    msgBox.setWindowIcon(QIcon(":/image/com.ico"));
    msgBox.setText("数据导出完成.");
    msgBox.exec();
}

void Widget::notetoolcloseSlots()
{
    if(noteobj!=NULL)
    {
        noteobj->hide();
        delete noteobj;
        noteobj=NULL;
    }
}

void Widget::UpKeyClickedSlots()
{
    if(comconflag)
    {
        if(curindex>=0)
        {
            QString _text=this->historycmdlist[curindex];
            if(_text!=""&&_text!=" ")
            {
                this->SendLineEdit->setText(_text);
            }
            curindex--;
        }
        else
        {
            curindex=9;
            QString _text=this->historycmdlist[curindex];
            if(_text!=""&&_text!=" ")
            {
                this->SendLineEdit->setText(_text);
            }
            curindex--;
        }
    }
}

void Widget::DownKeyClickedSlots()
{
    if(comconflag)
    {
        if(curindex<=9)
        {
            QString _text=this->historycmdlist[curindex];
            if(_text!=""&&_text!=" ")
            {
                this->SendLineEdit->setText(_text);
            }
            curindex++;
        }
        else
        {
            curindex=0;
            QString _text=this->historycmdlist[curindex];
            if(_text!=""&&_text!=" ")
            {
                this->SendLineEdit->setText(_text);
            }
            curindex++;
        }
    }
}

void Widget::RemoteMapBtnSlots()
{
    if(RemoteMapObj==NULL)
    {
        RemoteMapObj=new RemoteMapTool;
    }
    connect(this,SIGNAL(LocalCloseOkSignal()),RemoteMapObj,SLOT(LocalCloseOkSlots()));
    connect(this,SIGNAL(clientRecvTypeChangeSignal(bool)),RemoteMapObj,SLOT(clientRecvTypeChangeSlots(bool)));
    connect(this,SIGNAL(SaidRemoteConOkSignal(int)),RemoteMapObj,SLOT(SaidRemoteConOkSlots(int)));
    connect(this,SIGNAL(setInfoSignal(QByteArray)),RemoteMapObj,SLOT(setInfoSlots(QByteArray)));
    connect(this,SIGNAL(sendComInfoSignal(QByteArray)),RemoteMapObj,SLOT(sendComInfoSlots(QByteArray)));
    connect(this,SIGNAL(clientSendDataSignal(QByteArray)),RemoteMapObj,SLOT(clientSendDataSlots(QByteArray)));
    connect(this,SIGNAL(LocalRecvDataSignal(QByteArray)),RemoteMapObj,SLOT(LocalRecvDataSlots(QByteArray)));
    connect(this,SIGNAL(closeSerialPortSignal()),RemoteMapObj,SLOT(closeSerialPortSlots()));
    connect(RemoteMapObj,SIGNAL(clientConnectOkSignal(int)),this,SLOT(clientConnectOkSlots(int)));
    connect(RemoteMapObj,SIGNAL(RemoteMapToolCloseSignal()),this,SLOT(RemoteMapToolCloseSlots()));
    connect(RemoteMapObj,SIGNAL(RemoteMapToolOpenSignal(int)),this,SLOT(RemoteMapToolOpenSlots(int)));
    connect(RemoteMapObj,SIGNAL(CominfoSignal(QByteArray)),this,SLOT(CominfoSlots(QByteArray)));
    connect(RemoteMapObj,SIGNAL(RemoteMapToolSetSignal(QByteArray)),this,SLOT(RemoteMapToolSetSlots(QByteArray)));
    connect(RemoteMapObj,SIGNAL(clientRecvDataSignal(QByteArray)),this,SLOT(clientRecvDataSlots(QByteArray)));
    connect(RemoteMapObj,SIGNAL(clientRecvDataRealSignal(QString)),this,SLOT(clientRecvDataRealSlots(QString)));
    connect(RemoteMapObj,SIGNAL(RecvTypeChangeSignals(QByteArray)),this,SLOT(RecvTypeChangeSlots(QByteArray)));
    connect(RemoteMapObj,SIGNAL(SendTypeChangeSignals(QByteArray)),this,SLOT(SendTypeChangeSlots(QByteArray)));
    connect(RemoteMapObj,SIGNAL(ReadCloseSignal()),this,SLOT(ReadCloseSlots()));
    connect(RemoteMapObj,SIGNAL(closeoksignal()),this,SLOT(closeokSlots()));
    RemoteMapObj->show();
}

void Widget::RemoteMapToolCloseSlots()
{
    if(RemoteMapObj!=NULL)
    {
        RemoteMapObj->hide();
        delete RemoteMapObj;
        RemoteMapObj=NULL;
    }
}

void Widget::SendFileBtnSlots()
{
    QString fileName=QFileDialog::getOpenFileName(this,\
                                                  "选择发送文件"\
                                                  ,QDir::currentPath(),"files(*.*)");
    if(fileName=="") return ;
    if(resendflag)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("提示");
        msgBox.setWindowIcon(QIcon(":/image/com.ico"));
        msgBox.setText("请先关闭重复发送.");
        msgBox.exec();
        return ;
    }
    QFile file(fileName);
    if(file.open(QIODevice::ReadWrite))
    {
        while(!file.atEnd())
        {
            char buf[128]={0};
            //读取一行数据
            qint64 length=file.read(buf,128);
            if(length!=-1)
            {
                if(remoteType==0)
                {
                    qint64 sendNum=SerialPort->write(buf,length);
                    if(sendNum==-1)
                    {
                        //发送失败
                        errorValue=SerialPort->error();
                        showErrorMsg(errorValue);
                        return ;
                    }
                    SerialPort->flush();
                }
                else if(remoteType==2)
                {
                    QString tempdata=tr("%1").arg(buf);
                    QByteArray temp=tempdata.toLatin1();
                    QByteArray sendstr="SendData&Chick#"+temp;
                    emit clientSendDataSignal(sendstr);
                }
            }
        }
    }
    file.close();
    QMessageBox msgBox;
    msgBox.setWindowTitle("提示");
    msgBox.setWindowIcon(QIcon(":/image/com.ico"));
    msgBox.setText("文件发送完毕.");
    msgBox.exec();
}

void Widget::RemoteMapToolOpenSlots(int type)
{
    if(type==1)                                          //本地
    {
        ComBox->setEnabled(false);
        BaudRateBox->setEnabled(false);
        DataBitBox->setEnabled(false);
        CheckBitBox->setEnabled(false);
        StopBitBox->setEnabled(false);
        FlowCtlBox->setEnabled(false);
        RAsciiRadioBtn->setEnabled(false);
        RHexRadioBtn->setEnabled(false);
        AutoChgeLineBtn->setEnabled(false);                         //自动换行
        StopAndContinRecvBtn->setEnabled(false);                    //暂停继续接收按钮
        ShowSendDataBtn->setEnabled(false);                         //显示发送
        ConnectComBtn->setEnabled(false);                           //连接串口
        ShowLocalTimeBtn->setEnabled(false);                        //显示时间
        ClearReadBtn->setEnabled(false);
        SAsciiRadioBtn->setEnabled(false);
        SHexRadioBtn->setEnabled(false);

        ReSendBtn->setEnabled(false);                                //重复发送时间
        ReSendSpinBox->setEnabled(false);
        RecvRateBtn->setEnabled(false);                              //接收频率
        RecvRateSpinBox->setEnabled(false);
        OutPutBtn->setEnabled(false);
        SubmitBtn->setEnabled(false);                                //发送串口
        SendFileBtn->setEnabled(false);                               //发送文件按钮
        SendLineEdit->setEnabled(false);
        QByteArray replystr;
        if(nSerialNum==0)
        {
            replystr="Not Com";
        }
        else
        {
            replystr="ComInfo&";
            for(unsigned i=0;i<nSerialNum;++i)
            {
                QString SerialName=SerialList[i].portName();
                replystr+=SerialName+"#";
                QString SerialDesp=SerialList[i].description();                                      //串口设备的描述信息
                replystr+=SerialDesp+"@";
            }
        }
        emit sendComInfoSignal(replystr);
    }
    else if(type==2)                                     //远程
    {
    }
    remoteType=type;
}

void Widget::CominfoSlots(QByteArray data)
{

    data.remove(0,data.indexOf("&")+1);
    while(data.indexOf("@")>0)
    {
        QString comname=data.mid(0,data.indexOf("#"));
        data.remove(0,data.indexOf("#")+1);
        this->ComBox->addItem(QIcon(":/image/com.ico"),comname);
        QString comdes=data.mid(0,data.indexOf("@"));
        data.remove(0,data.indexOf("@")+1);
        cominfomap.insert(comname,comdes);
    }
    this->ComBox->setCurrentIndex(0);
    QString t_cominfo="\n\n\t串口信息："+cominfomap.value(this->ComBox->currentText());
    this->ReadTextEdit->setText(t_cominfo);
}

void Widget::RemoteMapToolSetSlots(QByteArray data)
{
#ifdef XLMDEBUG
    qDebug()<<"recv:"<<data;
#endif
    comconflag=false;
    if(rsendtimer!=NULL)
        rsendtimer->disconnect();
    if(SerialPort!=NULL)
    {
        SerialPort->close();
        SerialPort=NULL;
    }
    //解析数据到界面，并打开串口对象
    QString headstr=data.mid(0,data.indexOf("&"));
    if(headstr=="SetMsg")
    {
        data.remove(0,data.indexOf("&")+1);
        QString setcomname=data.mid(0,data.indexOf("#"));       //串口名称
        SerialPort=new QSerialPort(setcomname);
        data.remove(0,data.indexOf("#")+1);
        if(!SerialPort)
        {
            QSerialPort::SerialPortError errorVal=SerialPort->error();
            QMessageBox msgBox;
            msgBox.setWindowTitle("提示");
            msgBox.setWindowIcon(QIcon(":/image/com.ico"));
            msgBox.setText("初始化串口设备失败.");
            msgBox.exec();
            emit SaidRemoteConOkSignal(0);
            return ;
        }
        if(!SerialPort->open(QIODevice::ReadWrite))
        {
            QMessageBox msgBox;
            msgBox.setWindowTitle("提示");
            msgBox.setWindowIcon(QIcon(":/image/com.ico"));
            msgBox.setText("打开串口设备失败.");
            msgBox.exec();
            emit SaidRemoteConOkSignal(0);
            return ;
        }
        connect(SerialPort,SIGNAL(readyRead()),this,SLOT(OnReadyReadSlots()));

        this->curbaudstr=data.mid(0,data.indexOf("#"));
        data.remove(0,data.indexOf("#")+1);
        curdatabitstr=data.mid(0,data.indexOf("#"));
        data.remove(0,data.indexOf("#")+1);
        curParitystr=data.mid(0,data.indexOf("#"));
        data.remove(0,data.indexOf("#")+1);
        curstopbitstr=data.mid(0,data.indexOf("#"));
        data.remove(0,data.indexOf("#")+1);
        curflowStr=data.mid(0,data.indexOf("#"));
        data.remove(0,data.indexOf("#")+1);
        QString rflag=data.mid(0,data.indexOf("#"));
        data.remove(0,data.indexOf("#")+1);
        QString sflag=data.mid(0,data.indexOf("#"));
        data.remove(0,data.indexOf("#")+1);
        if(rflag=="HEX")
        {
            this->recvtype=true;
        }
        else
        {
            this->recvtype=false;
        }
        if(sflag=="HEX")
        {
            this->sendtype=true;
        }
        else
        {
            this->sendtype=false;
        }
        QString restop=data.mid(0,data.indexOf("@"));
        if(restop=="RNO")
        {
            this->resendflag=false;
        }
        else
        {
            this->resendflag=true;
        }
        //        qDebug()<<setcomname<<" "<<curbaudstr<<" "<<curdatabitstr<<" "<<curParitystr<<" "<<curstopbitstr<<" "\
        //               <<curflowStr<<" "<<rflag<<" "<<sflag<<" "<<restop;
        //recv: "SetMsg&COM3#9600#CS8#None#1 Byte#None#HEX#ASCII#RNO@"
        setBaudRate();                                  //设置串口对象波特率
        setDataBit();                                   //设置串口对象数据位
        setStopBit();                                   //设置串口对象停止位
        setParityBit();                                 //设置串口对象奇偶校验位
        setFlowControl();                               //设置串口对象流控
        //反馈给客户端连接成功
        emit SaidRemoteConOkSignal(1);
    }
}

void Widget::clientConnectOkSlots(int param)
{
    QString res;
    if(param==1)
    {
        this->ReadTextEdit->clear();
        comconflag=true;
        ComBox->setEnabled(false);
        QPixmap pix1;
        ConnectComBtn->setText("断开连接");
        res="串口连接成功.";
        curStateLabel->setText("已连接");
    }
    else
    {
        res="串口连接失败.";
    }
    QMessageBox msgBox;
    msgBox.setWindowTitle("提示");
    msgBox.setWindowIcon(QIcon(":/image/com.ico"));
    msgBox.setText(res);
    msgBox.exec();
}

void Widget::clientRecvDataSlots(QByteArray datas)
{
    datas.remove(0,datas.indexOf("&")+1);
    QString typestr=datas.mid(0,datas.indexOf("#"));
    datas.remove(0,datas.indexOf("#")+1);
    if(typestr=="Enter")
    {
        qint64 sendNum;
        char * sendContent=datas.data();
        sendContent[datas.count()]=0x0D;                      //末尾加回车符
        sendNum=SerialPort->write(sendContent,datas.count()+1);
        if(sendNum==-1)
        {
            //发送失败
            errorValue=SerialPort->error();
            showErrorMsg(errorValue);
            return ;
        }
    }
    else if(typestr=="Chick")
    {
        qint64 sendNum;
        char * sendContent=datas.data();
        sendNum=SerialPort->write(sendContent,datas.count());
        if(sendNum==-1)
        {
            //发送失败
            errorValue=SerialPort->error();
            showErrorMsg(errorValue);
            return ;
        }
    }
}

void Widget::clientRecvDataRealSlots(QString data)       //客户端具体读到的数据
{
    while(data.contains("RecvData"))
    {
        data.remove(0,data.indexOf("&")+1);
        QString _tmp=data.mid(0,data.indexOf("$"));
        data.remove(0,data.indexOf("$")+1);
        ++recvcnt;
        QString recvcntstr=tr("%1").arg(recvcnt);
        TxValLabel->setText(recvcntstr);
        showRecvMsg(_tmp);
        sameflag=true;
    }
    sameflag=false;
}

void Widget::RecvTypeChangeSlots(QByteArray data)
{
    data.remove(0,data.indexOf("&")+1);
    if(data.contains("HEX"))
    {
        this->recvtype=true;
    }
    else
    {
        this->recvtype=false;
    }
}

void Widget::SendTypeChangeSlots(QByteArray data)
{
    data.remove(0,data.indexOf("&")+1);
    if(data.contains("HEX"))
    {
        this->sendtype=true;
    }
    else
    {
        this->sendtype=false;
    }
}

void Widget::ReadCloseSlots()
{
    sendcnt=0;                                //发送计数
    recvcnt=0;
    comconflag=false;
    sendtype=false;                                        //false ascii true hex
    recvtype=true;
    resendrate=10;
    recvflag=false;                                        //接收标记  false 不按频率接收 true 按频率接收
    recvrate=10;
    comconflag=false;
    if(rsendtimer!=NULL)
        rsendtimer->disconnect();
    if(SerialPort!=NULL)
    {
        SerialPort->close();
        SerialPort=NULL;
    }
    emit LocalCloseOkSignal();                          //本地断开成功
}

void Widget::closeokSlots()                             //远程断开成功按钮
{
    sendcnt=0;                                //发送计数
    recvcnt=0;
    comconflag=false;
    sendtype=false;                                        //false ascii true hex
    this->SAsciiRadioBtn->setChecked(true);
    recvtype=true;
    this->RHexRadioBtn->setChecked(true);
    resendrate=10;
    showcurtimeflag=true;
    this->ShowLocalTimeBtn->setChecked(true);
    showsendflag=false;
    this->ShowSendDataBtn->setChecked(false);
    recvflag=false;                                        //接收标记  false 不按频率接收 true 按频率接收
    recvrate=10;
    this->RecvRateBtn->setChecked(false);
    this->ReSendBtn->setChecked(false);
    comconflag=false;
    ComBox->setEnabled(true);
    curStateLabel->setText("未连接");
    ConnectComBtn->setText("连接串口");
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter pa(this);
    QRect s(0,0,this->width(),this->height());
    QRect t(0,0,this->bkimage.width(),this->bkimage.height());
    pa.drawImage(s,this->bkimage,t);
}

void Widget::closeEvent(QCloseEvent *)
{
    if(helpobj!=NULL)
    {
        helpobj->hide();
        delete helpobj;
        helpobj=NULL;
    }
    if(crcobj!=NULL)
    {
        crcobj->hide();
        delete crcobj;
        crcobj=NULL;
    }
    if(outputobj!=NULL)
    {
        delete outputobj;
        outputobj=NULL;
    }
    if(noteobj!=NULL)
    {
        delete noteobj;
        noteobj=NULL;
    }
    if(RemoteMapObj!=NULL)
    {
        RemoteMapObj->hide();
        delete RemoteMapObj;
        RemoteMapObj=NULL;
    }
}

