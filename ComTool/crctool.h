#ifndef CRCTOOL_H
#define CRCTOOL_H

#include <QObject>
#include <QWidget>
#include "head.h"

class CrcTool : public QWidget
{
    Q_OBJECT
public:
    explicit CrcTool(QWidget *parent = 0);
    ~CrcTool();
    void init();
    void connectfunction();
    WORD CalCheckCRC(char* lpBuf,int iLen);
signals:
    void crctoolclosesignal();
public slots:
    void CalcBtnSlots();
protected:
    void closeEvent(QCloseEvent *);
private:
    QLabel* EnterLabel;
    QLineEdit* EnterLineEdit;
    QLabel* TypeLabel;
    QComboBox* TypeComBox;
    QPushButton* CalcBtn;                                         //计算按钮
    QLabel* ResLabel;                                             //计算结果
    /**************************/


};

#endif // CRCTOOL_H
