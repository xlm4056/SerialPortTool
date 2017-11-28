#include "outputthread.h"

OutPutThread::OutPutThread()
{
    ReadTextEdit=NULL;
    typeflag=0;
    filepath="Data.txt";
}

OutPutThread::~OutPutThread()
{

}

void OutPutThread::settypeflag(int _typeflag)
{
    typeflag=_typeflag;
}

void OutPutThread::setfilepath(QString _filepath)
{
    filepath=_filepath;
}

void OutPutThread::setReadTextEdit(QTextEdit *_ReadTextEdit)
{
    ReadTextEdit=_ReadTextEdit;
}

void OutPutThread::run()
{
    QFile file(filepath);
    file.open(QIODevice::ReadWrite|QIODevice::Append|QIODevice::Text);
    QTextStream out(&file);
    out<<ReadTextEdit->toPlainText()<<endl;
    file.close();
    if(typeflag==1)
    {
        emit outputfinishedsignal();
    }
    else if(typeflag==2)
    {
        emit outputfinishedsignal2();
    }
}

