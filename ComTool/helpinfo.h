#ifndef HELPINFO_H
#define HELPINFO_H

#include <QObject>
#include <QWidget>
#include "head.h"

class HelpInfo : public QWidget
{
    Q_OBJECT
public:
    explicit HelpInfo(QWidget *parent = 0);
    ~HelpInfo();
    void init();
signals:
    void helpinfoclosesignal();
public slots:
protected:
    void closeEvent(QCloseEvent *);
private:
    QTextEdit* HelpTextEdit;
    QVBoxLayout* v;
};

#endif // HELPINFO_H
