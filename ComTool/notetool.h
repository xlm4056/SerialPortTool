#ifndef NOTETOOL_H
#define NOTETOOL_H

#include <QObject>
#include <QWidget>
#include "head.h"
#include "outputthread.h"

class NoteTool : public QWidget
{
    Q_OBJECT
public:
    explicit NoteTool(QWidget *parent = 0);
    ~NoteTool();
    void init();
    void connectfunction();
signals:
    void notetoolclosesignal();
public slots:
    void SaveBtnSlots();                                            //发送槽函数
    void OutPutBtnSlots();                                          //导出槽函数
    void ClearBtnSlots();                                           //清空槽函数
    void outputfinishedSlots2();                                    //导出完成槽函数
protected:
    void closeEvent(QCloseEvent*);

private:
    QTextEdit* NoteTextEdit;
    QPushButton* SaveBtn;                                          //保存
    QPushButton* OutPutBtn;                                        //导出
    QPushButton* ClearBtn;                                         //清空
    /*******************************************************************/
    OutPutThread* outputobj;
    /********************************************************************/
    QString curdir;
    QString filepath;
};

#endif // NOTETOOL_H
