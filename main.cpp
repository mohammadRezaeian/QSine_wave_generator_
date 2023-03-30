#include <QCoreApplication>
#include <QTimer>
#include <QDebug>
#include <QDateTime>
#include <QtMath>
#include <QVector>
#include <QElapsedTimer>

void wait( int ms ) {
   QElapsedTimer timer;
   timer.start();

   while ( timer.elapsed() < ms )
       QCoreApplication::processEvents();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    static QTimer dataTimer;
    dataTimer.start(0);
    // if i want set wait
//    wait(5000);
    QObject::connect(&dataTimer, &QTimer::timeout, [](){
        static QTime time(QTime::currentTime());
        double key = time.elapsed()/1000.0;
        static double lastPointKey = 0;
        if (key-lastPointKey > 0.001)
        {
           double _firstNumber  = (key, qSin(key)+qrand()/(double)RAND_MAX*808*qSin(key/0.3843));
           double _secondNumber = (key, qSin(key)+qrand()/(double)RAND_MAX*535*qSin(key/0.4364));
           bool   _checkFirstNumber  = 0  <= (_firstNumber  / 2);
           bool   _checkSecondNumber = 0  <= (_secondNumber / 2);


           if(_checkFirstNumber && _checkSecondNumber)
           {
               QVector<double> _vector;
               _vector.push_back(_firstNumber);
               _vector.push_back(_secondNumber);
               qDebug() << _vector;
           }

            lastPointKey = key;
            // if i want set stop
            //dataTimer.stop();
        }
    });
    return a.exec();
}
