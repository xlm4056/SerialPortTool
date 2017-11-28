#ifndef OUTPUTTHREAD_H
#define OUTPUTTHREAD_H

#include <QObject>
#include "head.h"

class OutPutThread:public QThread
{
    Q_OBJECT
public:
    OutPutThread();
    ~OutPutThread();
    void settypeflag(int _typeflag);
    void setfilepath(QString _filepath);
    void setReadTextEdit(QTextEdit* _ReadTextEdit);
signals:
    void outputfinishedsignal();
    void outputfinishedsignal2();
protected:
    virtual void run();
private:
    QTextEdit*     ReadTextEdit;
    QString        filepath;
    int            typeflag;                                   //调用类型标记 1 代表widget 2 代表notetool
};

#endif // OUTPUTTHREAD_H
