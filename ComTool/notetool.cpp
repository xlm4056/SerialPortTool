#include "notetool.h"

NoteTool::NoteTool(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("笔记本");
    this->setWindowIcon(QIcon(":/image/note.ico"));
    this->setFixedSize(500,600);
    NoteTextEdit=new QTextEdit;
    NoteTextEdit->setStyleSheet("color:brown");
    NoteTextEdit->setPlaceholderText("请在此添加笔记内容.");
    NoteTextEdit->setFont(QFont("Timers",10,QFont::Bold));
    SaveBtn=new QPushButton("保  存");                                          //保存
    OutPutBtn=new QPushButton("导  出");                                        //导出
    ClearBtn=new QPushButton("清  空");                                         //清空
    QHBoxLayout* h1=new QHBoxLayout;
    h1->addStretch();
    h1->addWidget(SaveBtn);
    h1->addWidget(OutPutBtn);
    h1->addWidget(ClearBtn);
    h1->addStretch();

    QVBoxLayout* v=new QVBoxLayout;
    v->addWidget(NoteTextEdit);
    v->addLayout(h1);
    this->setLayout(v);
    init();
    connectfunction();
}

NoteTool::~NoteTool()
{

}

void NoteTool::init()
{
    outputobj=NULL;
    curdir=QCoreApplication::applicationDirPath();
    filepath=curdir+"/database/file.txt";
    QFileInfo fileinfo(filepath);
    if(fileinfo.isFile())
    {
        //读取文件
        QFile file(filepath);
        if(file.open(QIODevice::ReadWrite))
        {
            while(!file.atEnd())
            {
                char buf[1024]={0};
                //读取一行数据
                qint64 length=file.readLine(buf,1024);
                if(length!=-1)
                {
                    QString content=tr("%1").arg(buf);
                    NoteTextEdit->append(content);
                }
            }
        }
         file.close();
    }
    else
    {
        //创建文件
        QFile file(filepath);
        file.open(QIODevice::ReadWrite|QIODevice::Text);
        file.close();
    }

}

void NoteTool::connectfunction()
{
    connect(SaveBtn,SIGNAL(clicked()),this,SLOT(SaveBtnSlots()));
    connect(OutPutBtn,SIGNAL(clicked()),this,SLOT(OutPutBtnSlots()));
    connect(ClearBtn,SIGNAL(clicked()),this,SLOT(ClearBtnSlots()));
}

void NoteTool::SaveBtnSlots()
{
    QFileInfo tfile(filepath);
    if(tfile.isFile())
    {
        //删除掉
        QFile::remove(filepath);
    }

    QFile file(filepath);
    file.open(QIODevice::ReadWrite|QIODevice::Append|QIODevice::Text);
    QTextStream out(&file);
    out<<NoteTextEdit->toPlainText()<<endl;
    file.close();
    QMessageBox msgBox;
    msgBox.setWindowTitle("提示");
    msgBox.setWindowIcon(QIcon(":/image/com.ico"));
    msgBox.setText("数据保存成功.");
    msgBox.exec();
    return ;
}

void NoteTool::OutPutBtnSlots()
{
    //开一个线程进行导出操作
    QString recvstr=this->NoteTextEdit->toPlainText();
    if(recvstr=="")
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("提示");
        msgBox.setWindowIcon(QIcon(":/image/com.ico"));
        msgBox.setText("当前没有数据可导出.");
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
    connect(outputobj,SIGNAL(outputfinishedsignal2()),this,SLOT(outputfinishedSlots2()));
    outputobj->settypeflag(2);
    outputobj->setfilepath(filename);
    outputobj->setReadTextEdit(NoteTextEdit);
    outputobj->start();
}

void NoteTool::ClearBtnSlots()
{
    this->NoteTextEdit->clear();
}

void NoteTool::outputfinishedSlots2()
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

void NoteTool::closeEvent(QCloseEvent *)
{
    emit notetoolclosesignal();
}

