#include "widget.h"
#include <QIcon>
#include <QTextCodec>
#include <QMessageBox>
#include <QApplication>
#include <QtCore/QSharedMemory>
int assumeSingleInstance(const char * program)
{
    static QSharedMemory shm(program);
    if(shm.create(100)==false)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
int main(int argc, char *argv[])
{
    QTextCodec* codec=QTextCodec::codecForName("utf8");              //解决中文乱码问题
    QTextCodec::setCodecForLocale(codec);
    QApplication a(argc, argv);
//    if(assumeSingleInstance("ComTool")<0)                          //判断程序是否正在运行
//    {
//        QMessageBox msgBox;
//        msgBox.setWindowIcon(QIcon(":/image/com.ico"));
//        msgBox.setWindowTitle("提示");
//        msgBox.setText("串口调试正在运行中.");
//        msgBox.exec();
//        return -1;
//    }
    Widget w;
    w.show();
    return a.exec();
}
