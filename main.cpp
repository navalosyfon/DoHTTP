#include <QCoreApplication>
#include "downloader.h"
#include <stdio.h>
#include "gpstime.h"
#include <sys/time.h>
#include <iostream>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Gpstime t=Gpstime();
    t.s1970_t(1451994843.3);
    t.ymdhms_t(2016,01,5,11,54,3.3);

    t.add_h(1);
    t.just_now();
    std::cout<< " date = " << t.dd << "/" << t.mon << "/" << t.yyyy << std::endl;
    std::cout<< " heure= " << t.hh << ":" << t.mm << ":" << t.sec << std::endl;
    printf(" mjd  = %.10f\n", t.mjd );
    printf(" doy  = %d\n", t.doy );

    t.afficher();
    //t.print_dates();

/*------------ Time evaluation of the prog-----------------*/
   /* struct timeval start;
    gettimeofday(&start, NULL);
    printf("took %lu %lu\n",  start.tv_sec , start.tv_usec);*/



   Downloader d;
   d.doDownload(t.yyyy,t.doy);

//    return 0;
  return a.exec();
}







