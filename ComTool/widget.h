#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "head.h"
#include "helpinfo.h"
#include "crctool.h"
#include "notetool.h"
#include "outputthread.h"
#include "remotemaptool.h"
/*串口调试工具*/
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void init();
    void connectfunction();
    QByteArray HexStrToByteArray(QString str);                      //十六进制转ByteArray
    char ConvertHexChar(char ch);
    QString ByteArrayToHexStr(QByteArray data);                     //ByteArray转十六进制
    void initBaudRate();                                            //初始化波特率控件
    void ReadLoalComDevice();                                       //获取本地串口设备
    void setBaudRate();                                             //设置串口对象波特率
    void setDataBit();                                              //设置串口对象数据位
    void setStopBit();                                              //设置串口对象停止位
    void setParityBit();                                            //设置串口对象奇偶校验位
    void setFlowControl();                                          //设置串口对象流控
    QString getValueContent(QSerialPort::SerialPortError);          //转换为错误信息
    void showErrorMsg(QSerialPort::SerialPortError);                //显示错误信息
    void showRecvMsg(QString recvStr);                              //显示接收数据
    void showSendMsg(QByteArray sendArray);                         //显示发送数据
signals:
    void sendComInfoSignal(QByteArray);
    void setInfoSignal(QByteArray);
    void SaidRemoteConOkSignal(int);                                //通知远程客户端连接成功
    void clientSendDataSignal(QByteArray);
    void LocalRecvDataSignal(QByteArray);                           //本地读到数据
    void clientRecvTypeChangeSignal(bool);
    void closeSerialPortSignal();                                   //远程断开串口信号
    void LocalCloseOkSignal();
public slots:
    void ClearReadBtnSlots();                                       //清空读数据槽函数
    void ConnectComBtnSlots();                                      //连接串口槽函数
    void ReSendStateChangedSlots(int);                              //重复发送checkbox
    void ReSendSpinValChangeSlots(int);                             //重复发送值发生改变
    void RecvRateBtnSlots(int);                                     //接收频率checkbox
    void RecvRateSpinValChangeSlots(int);                           //接收频率值发生改变
    void OnReadyReadSlots();                                        //准备读串口数据ComReady
    void SubmitBtnSlots();                                          //发送数据到串口
    void EnterSendSlots();                                          //回车发送函数
    void currentIndexChangedSlots(int);                             //串口选择改变
    void SAsciiRadioBtnSlots();
    void SHexRadioBtnSlots();
    void RAsciiRadioBtnSlots();
    void RHexRadioBtnSlots();
    void ShowLocalTimeBtnSlots(int);                                //显示当前时间
    void ShowSendDataBtnSlots(int);                                 //显示发送的数据
    void showSendFormatWarnMsg();                                   //发送信息警告
    void timerresendTimeoutSlots();                                 //重复发送定时器
    void StopAndContinRecvBtnSlots();                               //暂停接收定时器
    void CrcToolBtnSlots();
    void CalcToolBtnSlots();
    void NoteToolBtnSlots();
    void HelpInfoBtnSlots();
    void helpinfocloseSlots();                                       //帮助页关闭槽函数
    void crctoolcloseSlots();                                        //crc工具关闭槽函数
    void OutPutBtnSlots();                                           //数据导出槽函数
    void outputfinishedSlots();                                      //导出完成槽函数
    void notetoolcloseSlots();                                       //笔记本页面关闭
    void UpKeyClickedSlots();                                        //上按键
    void DownKeyClickedSlots();                                      //下按键
    void RemoteMapBtnSlots();                                        //远程映射工具
    void RemoteMapToolCloseSlots();                                  //远程映射工具退出槽函数
    void SendFileBtnSlots();                                         //发送文件槽函数
    //远程工具处理
    void RemoteMapToolOpenSlots(int);
    void CominfoSlots(QByteArray);
    void RemoteMapToolSetSlots(QByteArray);                           //远程主机点击连接传送设置参数
    void clientConnectOkSlots(int);                                   //客户端连接ok
    void clientRecvDataSlots(QByteArray);                             //客户端接收数据
    void clientRecvDataRealSlots(QString);                         //远程客户端真实接收到串口数据
    void RecvTypeChangeSlots(QByteArray);                           //本地处理远程客户端改变接收类型
    void SendTypeChangeSlots(QByteArray);
    void ReadCloseSlots();
    void closeokSlots();
protected:
    void paintEvent(QPaintEvent *);
    void closeEvent(QCloseEvent *);
private:
    QGroupBox * ComGrpBox;
    QLabel*     ComLabel;                                 //串口
    QComboBox*  ComBox;
    QLabel*     BaudRateLabel;                            //波特率
    QComboBox*  BaudRateBox;
    QLabel*     DataBitLabel;                             //数据位
    QComboBox*  DataBitBox;
    QLabel*     CheckBitLabel;                            //校验位
    QComboBox*  CheckBitBox;
    QLabel*     StopBitLabel;                             //停止位
    QComboBox*  StopBitBox;
    QLabel*     FlowCtlLabel;                             //流控
    QComboBox*  FlowCtlBox;

    QGroupBox *   ReadGrpBox;
    QRadioButton* RAsciiRadioBtn;
    QRadioButton* RHexRadioBtn;
    QCheckBox*    AutoChgeLineBtn;                         //自动换行
    QPushButton*  StopAndContinRecvBtn;                    //暂停继续接收按钮
    QCheckBox*    ShowSendDataBtn;                         //显示发送
    QPushButton*  ConnectComBtn;                           //连接串口
    QCheckBox*    ShowLocalTimeBtn;                        //显示时间
    QPushButton*  ClearReadBtn;

    QGroupBox *   SendGrpBox;
    QRadioButton* SAsciiRadioBtn;
    QRadioButton* SHexRadioBtn;

    QCheckBox*    ReSendBtn;                                //重复发送时间
    QSpinBox*     ReSendSpinBox;
    QLabel*       ReSendSuffixLabel;
    QCheckBox*    RecvRateBtn;                              //接收频率
    QSpinBox*     RecvRateSpinBox;
    QLabel*       RecvRateSuffixLabel;

    QGroupBox *   ToolGrpBox;                              //工具箱
    QPushButton*  CrcToolBtn;                              //Crc
    QPushButton*  CalcToolBtn;                             //Calc
    QPushButton*  NoteToolBtn;                             //笔记
    QPushButton*  RemoteMapBtn;                            //远程调试
    QPushButton*  HelpInfoBtn;                             //帮助信息

    QTextEdit*    ReadTextEdit;                             //接受区域
    QLineEdit*    SendLineEdit;                             //发送区域
    QPushButton*  SubmitBtn;                                //发送串口

    QLabel* TxLabel;
    QLabel* TxValLabel;
    QLabel* TxValSuffixLabel;
    QLabel* SxLabel;
    QLabel* SxValLabel;
    QLabel* SxValSuffixLabel;
    QLabel* StartTimeLabel;                                 //软件开启时间
    QLabel* curStateLabel;                                  //当前连接状态
    QPushButton* OutPutBtn;                                 //数据导出
    QPushButton* SendFileBtn;                               //发送文件按钮
    /****************************************/
    HelpInfo* helpobj;
    CrcTool*  crcobj;
    OutPutThread *outputobj;
    NoteTool* noteobj;
    RemoteMapTool* RemoteMapObj;
    /****************************************/
    QSerialPort* SerialPort;                                //串口对象
    QSerialPortInfo* SerialInfo;
    QList<QSerialPortInfo>SerialList;
    QString  curbaudstr;                                    //当前波特率
    QString curdatabitstr;                                  //当前数据位
    QString curParitystr;                                   //当前校验位
    QString curstopbitstr;                                  //当前停止位
    QString curflowStr;                                     //当前流控

    QImage bkimage;
    unsigned long sendcnt;                                  //发送计数
    unsigned long recvcnt;                                  //接收计数
    bool comconflag;                                        //串口连接标记
    bool sendtype;                                          //false ascii true hex
    bool recvtype;                                          //false ascii true hex
    unsigned int resendrate;                                //重复发送频率
    bool resendflag;                                        //重复发送标记
    bool showcurtimeflag;                                   //显示当前时间的标记
    bool showsendflag;                                      //显示发送标记
    bool recvflag;                                          //接收标记  false 不按频率接收 true 按频率接收
    bool recvstopflag;                                      //暂停接收标记
    unsigned int recvrate;                                  //接收频率
    QString errorInfo;
    QSerialPort::SerialPortError errorValue;
    QString timeinfo;
    QDateTime currentTime;
    QTimer    *rsendtimer;                                  //重复发送定时器
    QString   historycmdlist[10];                           //保存历史命令
    int       curindex;                                     //当前索引
    int       insertindex;                                  //插入索引
    int       ReadTextFontSize;                             //读区域当前字体大小
    unsigned int nSerialNum;                                //本地串口数量
    /****************************************************************************/
    bool sameflag;                                          //本地发来的数据处理是区别是不是同一包数据
    int remoteType;                                         //远程类型0 不开  1 本地 2远程
    QMap<QString,QString> cominfomap;
};

#endif // WIDGET_H
