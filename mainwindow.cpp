#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupSignals();
    source.clear();
    ui->label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->label->setScaledContents(true);
    ui->scrollArea->setAcceptDrops(false);
    setAcceptDrops(true);

    quality = 40 ;
    name = "a.jpg";
    lbl = "PREVIEW" ;
    dlg = NULL;


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("text/uri-list"))
        event->acceptProposedAction();
}

void MainWindow::dropEvent(QDropEvent *event)
{
    QList<QUrl> urls = event->mimeData()->urls();
    if (urls.isEmpty())
        return;

    QString fileName = urls.first().toLocalFile();
    if (fileName.isEmpty())
        return;

    displayImage(fileName);
    // if (readFile(fileName))
    setWindowTitle(tr("%1 - %2").arg(fileName)
                   .arg(tr("Drag File")));
}

void MainWindow::displayImage(QString fileName)
{
    source = fileName;
    QImage tempImage;
    try
    {
        tempImage.load(fileName);
        //pic.read( qPrintable(fileName));
    }
    catch(Exception &error)
    {
        return;

    }


    //    pic.magick("XPM");
    //    pic.write(&blob);
    //    imgData = ((char*)(blob.data()));
    //    pixmap.loadFromData(imgData, "XPM");
    ui->label->setPixmap(QPixmap::fromImage(tempImage));



}

void MainWindow::adjustScrollBar(QScrollBar *scrollBar, double factor)
{
    scrollBar->setValue(int(factor * scrollBar->value()
                            + ((factor - 1) * scrollBar->pageStep()/2)));
}

void MainWindow::setupSignals()
{


    connect(ui->actionTo_jpeg_high, SIGNAL(triggered()), this, SLOT(saveHigh()));
    connect(ui->actionTo_jpeg_Mail, SIGNAL(triggered()), this, SLOT(saveLow()));
    connect(ui->actionOptions, SIGNAL(triggered()), this, SLOT(showOpt()));



}

void MainWindow::saveHigh()
{
    if(source == NULL)
        return;
    try
    {
        pic.read( qPrintable(source));
    }
    catch(Exception &error)
    {
        QImage tempImage;

        tempImage.load(source);
        pic =  Image(Magick::Geometry(tempImage.width(), tempImage.height()), Magick::ColorRGB(0.5, 0.2, 0.3));

        double scale = 1 / 256.0;
        pic.modifyImage();
        Magick::PixelPacket *pixels;
        Magick::ColorRGB mgc;
        for (int y = 0; y < tempImage.height(); y++) {
            pixels = pic.setPixels(0, y, pic.columns(), 1);
            for (int x = 0; x < tempImage.width(); x++) {
                QColor pix = tempImage.pixel(x, y);
                //      *pixels++ = Magick::ColorRGB(256 * pix.red(), 256 * pix.green(), 256 * pix.blue());
                mgc.red(scale *pix.red());
                mgc.green(scale *pix.green());
                mgc.blue(scale *pix.blue());
                //      *pixels++ = Magick::ColorRGB(scale *pix.red(), scale * pix.green(), scale * pix.blue());
                *pixels++ = mgc;
            }
            pic.syncPixels();
        }

    }

    QString path = source.left(source.lastIndexOf("/"));
    pic.magick("JPEG");
    path += name;
    pic.write(path.toStdString());


}

void MainWindow::saveLow()
{
    if(source == NULL)
        return;
    try
    {
        pic.read( qPrintable(source));
    }
    catch(Exception &error)
    {
        QImage tempImage;

        tempImage.load(source);
        pic =  Image(Magick::Geometry(tempImage.width(), tempImage.height()), Magick::ColorRGB(0.5, 0.2, 0.3));

        double scale = 1 / 256.0;
        pic.modifyImage();
        Magick::PixelPacket *pixels;
        Magick::ColorRGB mgc;
        for (int y = 0; y < tempImage.height(); y++) {
            pixels = pic.setPixels(0, y, pic.columns(), 1);
            for (int x = 0; x < tempImage.width(); x++) {
                QColor pix = tempImage.pixel(x, y);
                //      *pixels++ = Magick::ColorRGB(256 * pix.red(), 256 * pix.green(), 256 * pix.blue());
                mgc.red(scale *pix.red());
                mgc.green(scale *pix.green());
                mgc.blue(scale *pix.blue());
                //      *pixels++ = Magick::ColorRGB(scale *pix.red(), scale * pix.green(), scale * pix.blue());
                *pixels++ = mgc;
            }
            pic.syncPixels();
        }

    }

    QString path = source.left(source.lastIndexOf("/"));
    pic.magick("JPEG");
    pic.annotate(lbl.toAscii().data(),CenterGravity);
    pic.quality(quality);
    path += name;
    pic.write(path.toStdString());


}

void MainWindow::showOpt()
{
    if(dlg)
    {
        dlg->show();
    }else
    {
        optDialog *dlg = new optDialog(this);
        dlg->show();
        dlg->exec();
    }
    if(dlg->exec() == QDialog::Accepted)
    {
        this->quality = dlg->quality;
        this->name = dlg->name;
        this->lbl = dlg->lbl;

    }


}

//QImage* MainWindow::toQImage(Image &image)
//{
//    qDebug() << "toQImage:" << image.columns() << image.rows();

//    QImage *newQImage = new QImage(image.columns(), image.rows(), QImage::Format_RGB32);
//    const Magick::PixelPacket *pixels;
//    Magick::ColorRGB rgb;
//    for (int y = 0; y < newQImage->height(); y++) {
//        pixels = image.getConstPixels(0, y, newQImage->width(), 1);
//        for (int x = 0; x < newQImage->width(); x++) {
//            rgb = (*(pixels + x));
//            newQImage->setPixel(x, y, QColor((int) (255 * rgb.red())
//                                             , (int) (255 * rgb.green())
//                                             , (int) (255 * rgb.blue())).rgb());
//        }
//    }
//    return newQImage;
//}


//Image* MainWindow::toImage(QImage& qimage)
//{
//    qDebug() << "toImage:" << qimage.width() << qimage.height();

//    Image *newImage = new Image(Magick::Geometry(qimage.width(), qimage.height()), Magick::ColorRGB(0.5, 0.2, 0.3));

//    double scale = 1 / 256.0;
//    newImage->modifyImage();
//    Magick::PixelPacket *pixels;
//    Magick::ColorRGB mgc;
//    for (int y = 0; y < qimage.height(); y++) {
//        pixels = newImage->setPixels(0, y, newImage->columns(), 1);
//        for (int x = 0; x < qimage.width(); x++) {
//            QColor pix = qimage.pixel(x, y);
//            //      *pixels++ = Magick::ColorRGB(256 * pix.red(), 256 * pix.green(), 256 * pix.blue());
//            mgc.red(scale *pix.red());
//            mgc.green(scale *pix.green());
//            mgc.blue(scale *pix.blue());
//            //      *pixels++ = Magick::ColorRGB(scale *pix.red(), scale * pix.green(), scale * pix.blue());
//            *pixels++ = mgc;
//        }
//        newImage->syncPixels();
//    }

//    return newImage;
//}
