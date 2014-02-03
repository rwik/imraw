#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <qmimedata.h>
#include <qimage.h>
#include <qscrollbar.h>
#include <QList>
#include <QUrl>
#include <Magick++.h>
#include <optdialog.h>


using namespace std;
using namespace Magick;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QString source;
    optDialog *dlg;
    int quality ;
    QString name ;
    QString lbl ;
    ~MainWindow();

protected:
    Image pic;
    QByteArray 	imgData;
    QPixmap		pixmap;
    Blob 			blob;


    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);



private:
    Ui::MainWindow *ui;
private slots:
    void  displayImage(QString fileName);
    void  adjustScrollBar(QScrollBar *scrollBar, double factor);
    void    setupSignals();
    void saveHigh();
    void saveLow();
    void showOpt();



};

#endif // MAINWINDOW_H
