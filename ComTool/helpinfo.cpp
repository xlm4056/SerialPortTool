#include "helpinfo.h"

HelpInfo::HelpInfo(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("帮助信息");
    this->setWindowIcon(QIcon(":/image/help.ico"));
    this->setFixedSize(500,600);
    HelpTextEdit=new QTextEdit;
    HelpTextEdit->setReadOnly(true);
    v=new QVBoxLayout;
    v->addWidget(HelpTextEdit);
    this->setLayout(v);
    init();
}

HelpInfo::~HelpInfo()
{

}

void HelpInfo::init()
{
    HelpTextEdit->append("\n2017.11.22 xieliming QtCreator IDE Serial Port Tool");
    HelpTextEdit->append("\n1.回车发送末尾附带回车字符;");
    HelpTextEdit->append("2.点击发送按钮发送末尾不附带回车字符;");
    HelpTextEdit->append("3.CRC工具可以直接在接收区域复制内容过来计算;");
    HelpTextEdit->append("4.上下按钮调出历史命令，历史命令保存10条;");
    HelpTextEdit->append("5.图标右下角白色按钮为文件发送按钮;");
    HelpTextEdit->append("6.图标右下角绿色按钮为导出接收区域的数据按钮;");
}

void HelpInfo::closeEvent(QCloseEvent *event)
{
    if(HelpTextEdit!=NULL)
    {
        delete HelpTextEdit;
        HelpTextEdit=NULL;
    }
    if(v!=NULL)
    {
        delete v;
        v=NULL;
    }
    emit helpinfoclosesignal();
}

