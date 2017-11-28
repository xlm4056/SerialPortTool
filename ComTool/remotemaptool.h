#ifndef REMOTEMAPTOOL_H
#define REMOTEMAPTOOL_H
/*远程映射工具*/
#include <QObject>
#include <QWidget>
#include "head.h"
/*远程映射*/

class RemoteMapTool : public QWidget
{
    Q_OBJECT
public:
    explicit RemoteMapTool(QWidget *parent = 0);
    ~RemoteMapTool();
    void inits();
    void connectfunction();
signals:
    void RemoteMapToolCloseSignal();
    void RemoteMapToolOpenSignal(int);                           //远程工具成功开启信号1 本地 2 远程
    void CominfoSignal(QByteArray);                              //发送回主操作页
    void RemoteMapToolSetSignal(QByteArray);
    void clientConnectOkSignal(int);                             //客户端连接ok
    void clientRecvDataSignal(QByteArray);
    void clientRecvDataRealSignal(QString);
    void RecvTypeChangeSignals(QByteArray);
    void SendTypeChangeSignals(QByteArray);
    void ReadCloseSignal();
    void closeoksignal();
public slots:
    void currentIndexChangedSlots(int index);
    void StartAndStopBtnSlots();
    void newconnectSlots();                                   //用新客户端来连接的槽函数
    void readyreadSlots();                                    //读取客户端发送过来的数据
    void ServerModeParsed(QByteArray data);                   //服务器解析数据
    void SaidRemoteConOkSlots(int);                              //通知远程连接成功
    //客户端函数
    void connectSlots();                                       //客户端连接成功槽函数
    void SocketreadyReadSlots();                               //客户端准备读服务器数据函数
    void SocketModeParsed(QByteArray data);                    //客户端解析数据
    void KeepLiveSlots();                                      //发送心跳线程
    void CntLiveTimerSlots();
    void LocalCloseOkSlots();
    /**************************************/
    void sendComInfoSlots(QByteArray);
    void setInfoSlots(QByteArray);
    void clientSendDataSlots(QByteArray);
    void LocalRecvDataSlots(QByteArray);
    void clientRecvTypeChangeSlots(bool);                     //远程客户端点改变了接收类型
    void closeSerialPortSlots();                              //远程断开串口发送到本地
protected:
    void closeEvent(QCloseEvent*);
private:
    QLabel*    CsTypeLabel;                                   //类型： 服务器  客户端
    QComboBox* CsTypeCombox;
    QLabel*    ServerIpLabel;
    QLineEdit* ServerIpLineEdit;
    QPushButton* StartAndStopBtn;
    QTextEdit*   LogTextEdit;
    QLabel*    StatueLabel;
    /********************************/
    QTcpServer* server;
    QTcpSocket* socket;
    /********************************/
    bool    startflag;                                        //启动标记
    unsigned cntlive;                                         //心跳计数
    QTimer* LiveTimer;                                        //心跳定时器
    QTimer* CntLiveTimer;                                     //本地服务器使用的计数
};

#endif // REMOTEMAPTOOL_H
