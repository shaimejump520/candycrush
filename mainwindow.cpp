#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <time.h>
#include <iostream>
#include <QSignalMapper>
#include <QLCDNumber>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->title->setPixmap(QPixmap(":/pics/title.jpg"));
    ui->Score->display(score);

    srand((unsigned)time(NULL));
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            q[i][j]=rand()%5+1;

            p[i][j]=new QPushButton("",this);
            p[i][j]->setGeometry(QRect(QPoint(300+j*60,50+i*60),QSize(60,60)));
            //p[i][j]->setFlat(true);
        }

    }
    t=0;
    step=15;
    ui->Step->display(step);
    score=0;
    ii=jj=mm=nn=0;

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(q[i][j]>10){

                c[i][j]=q[i][j]/10;
            }
            else
                c[i][j]=q[i][j];
        }
    }
    remove();
    drop();
    picture();
    click();

}

void MainWindow::picture()
{
    QPixmap pixmap;

   for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            switch (q[i][j]) {
            case 0:
                p[i][j]->setIcon(QIcon());
                break;
            case 1:
                pixmap.load(":/pics/1.jpg");
                p[i][j]->setIcon(pixmap);
                p[i][j]->setIconSize(QSize(55,55));
                break;
            case 2:
                pixmap.load(":/pics/2.jpg");
                p[i][j]->setIcon(pixmap);
                p[i][j]->setIconSize(QSize(55,55));
                break;
            case 3:
                pixmap.load(":/pics/3.jpg");
                p[i][j]->setIcon(pixmap);
                p[i][j]->setIconSize(QSize(55,55));
                break;
            case 4:
                pixmap.load(":/pics/4.jpg");
                p[i][j]->setIcon(pixmap);
                p[i][j]->setIconSize(QSize(55,55));
                break;
            case 5:
                pixmap.load(":/pics/5.jpg");
                p[i][j]->setIcon(pixmap);
                p[i][j]->setIconSize(QSize(55,55));
                break;
            case 11:
                pixmap.load(":/pics/11.jpg");
                p[i][j]->setIcon(pixmap);
                p[i][j]->setIconSize(QSize(55,55));
                break;
            case 12:
                pixmap.load(":/pics/12.jpg");
                p[i][j]->setIcon(pixmap);
                p[i][j]->setIconSize(QSize(55,55));
                break;
            case 21:
                pixmap.load(":/pics/21.jpg");
                p[i][j]->setIcon(pixmap);
                p[i][j]->setIconSize(QSize(55,55));
                break;
            case 22:
                pixmap.load(":/pics/22.jpg");
                p[i][j]->setIcon(pixmap);
                p[i][j]->setIconSize(QSize(55,55));
                break;
            case 31:
                pixmap.load(":/pics/31.jpg");
                p[i][j]->setIcon(pixmap);
                p[i][j]->setIconSize(QSize(55,55));
                break;
            case 32:
                pixmap.load(":/pics/32.jpg");
                p[i][j]->setIcon(pixmap);
                p[i][j]->setIconSize(QSize(55,55));
                break;
            case 41:
                pixmap.load(":/pics/41.jpg");
                p[i][j]->setIcon(pixmap);
                p[i][j]->setIconSize(QSize(55,55));
                break;
            case 42:
                pixmap.load(":/pics/42.jpg");
                p[i][j]->setIcon(pixmap);
                p[i][j]->setIconSize(QSize(55,55));
                break;
            case 51:
                pixmap.load(":/pics/51.jpg");
                p[i][j]->setIcon(pixmap);
                p[i][j]->setIconSize(QSize(55,55));
                break;
            case 52:
                pixmap.load(":/pics/52.jpg");
                p[i][j]->setIcon(pixmap);
                p[i][j]->setIconSize(QSize(55,55));
                break;
            case 111:
                pixmap.load(":/pics/111.jpg");
                p[i][j]->setIcon(pixmap);
                p[i][j]->setIconSize(QSize(55,55));
                break;
            case 222:
                pixmap.load(":/pics/222.jpg");
                p[i][j]->setIcon(pixmap);
                p[i][j]->setIconSize(QSize(55,55));
                break;
            case 333:
                pixmap.load(":/pics/333.jpg");
                p[i][j]->setIcon(pixmap);
                p[i][j]->setIconSize(QSize(55,55));
                break;
            case 444:
                pixmap.load(":/pics/444.jpg");
                p[i][j]->setIcon(pixmap);
                p[i][j]->setIconSize(QSize(55,55));
                break;
            case 555:
                pixmap.load(":/pics/555.jpg");
                p[i][j]->setIcon(pixmap);
                p[i][j]->setIconSize(QSize(55,55));
                break;

            case 1000:
                pixmap.load(":/pics/1000.jpeg");
                p[i][j]->setIcon(pixmap);
                p[i][j]->setIconSize(QSize(55,55));
                break;
        }
    }

}
}

void MainWindow::click()
{
    signalmapper=new QSignalMapper(this);
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            connect(p[i][j],SIGNAL(clicked()),signalmapper,SLOT(map()));
            signalmapper->setMapping(p[i][j],i*10+j);
        }
    }
    connect(signalmapper,SIGNAL(mapped(int)),this,SLOT(move(int)));

}
void MainWindow::star(int i, int j, int m, int n)
{
    int s=c[m][n];
    for(int a=0;a<10;a++){
        for(int b=0;b<10;b++){
            if(c[a][b]==s){
                q[a][b]=0;
                c[a][b]=0;
                score=score+20;
                ui->Score->display(score);
                picture();
                delay();
            }
        }
    }
    q[i][j]=0;
    c[i][j]=0;
    score=score+20;
    ui->Score->display(score);
    picture();
    drop();
    remove();

}

void MainWindow::special(int i, int j)
{
    if((q[i][j]/10)<10&&(q[i][j]/10)>=1){
        if(q[i][j]%10==1){
            for(int l=0;l<10;l++){
                //if(q[l][j]>10)
                //special(l,j);
                q[l][j]=0;
                score=score+20;
                ui->Score->display(score);
                picture();
                delay();
            }
        }
        if(q[i][j]%10==2){
            for(int l=0;l<10;l++){
                //if(q[i][l]>10)
                //special(i,l);
                q[i][l]=0;
                score=score+20;
                ui->Score->display(score);
                picture();
                delay();
            }
        }
    }
    if((q[i][j]/100)<10&&(q[i][j]/100)>=1){
        for(int a=-1;a<2;a++){
            for(int b=-1;b<2;b++){

                q[i+a][j+b]=0;
                picture();
                score=score+20;
                ui->Score->display(score);
                delay();
            }
        }

    }

}
void MainWindow::remove()
{
    int s=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(q[i][j]>100){
                c[i][j]=q[i][j]/100;
            }
            else if(q[i][j]>10){
                c[i][j]=q[i][j]/10;
            }
            else
                c[i][j]=q[i][j];
        }
    }

    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            k[i][j]=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(i>=0&&i<8&&c[i][j]==c[i+2][j]&&c[i][j]==c[i+1][j]){
                k[i][j]=1;
                k[i+2][j]=1;
                k[i+1][j]=1;
                special(i,j);
            }
            if(j>=0&&j<8&&c[i][j]==c[i][j+2]&&c[i][j]==c[i][j+1]){
                k[i][j]=1;
                k[i][j+2]=1;
                k[i][j+1]=1;
                special(i,j);
            }

            if(i<8&&j<8&&(c[i][j]==c[i][j+1]&&c[i][j]==c[i][j+2])&&(c[i][j]==c[i+1][j]&&c[i][j]==c[i+2][j]))
            {
                q[i][j]=c[i][j]*111;
                score=score+200;
                ui->Score->display(score);
                k[i][j+1]=1;
                k[i][j+2]=1;
                k[i+1][j]=1;
                k[i+2][j]=1;
                k[i][j]=0;

            }
            if(i>1&&j<8&&(c[i][j]==c[i][j+1]&&c[i][j]==c[i][j+2])&&(c[i][j]==c[i-1][j]&&c[i][j]==c[i-2][j]))
            {
                q[i][j]=c[i][j]*111;
               score=score+200;
               ui->Score->display(score);
                k[i][j+1]=1;
                k[i][j+2]=1;
                k[i-1][j]=1;
                k[i-2][j]=1;
                k[i][j]=0;
            }
            if(i>1&&j>1&&(c[i][j]==c[i][j-1]&&c[i][j]==c[i][j-2])&&(c[i][j]==c[i-1][j]&&c[i][j]==c[i-2][j]))
            {
                q[i][j]=c[i][j]*111;
                score=score+200;
                ui->Score->display(score);
                k[i][j-1]=1;
                k[i][j-2]=1;
                k[i-1][j]=1;
                k[i-2][j]=1;
                k[i][j]=0;
            }
            if(i<8&&j>1&&(c[i][j]==c[i][j-1]&&c[i][j]==c[i][j-2])&&(c[i][j]==c[i+1][j]&&c[i][j]==c[i+2][j]))
            {
                q[i][j]=c[i][j]*111;
                score=score+200;
                ui->Score->display(score);
                k[i][j-1]=1;
                k[i][j-2]=1;
                k[i+1][j]=1;
                k[i+2][j]=1;
                k[i][j]=0;
            }
            if(i<9&&i>0&&j<9&&j>0&&(c[i][j]==c[i][j-1]&&c[i][j]==c[i][j+1])&&(c[i][j]==c[i+1][j]&&c[i][j]==c[i-1][j]))
            {
                q[i][j]=c[i][j]*111;
                score=score+200;
                ui->Score->display(score);
                k[i][j-1]=1;
                k[i][j+1]=1;
                k[i+1][j]=1;
                k[i-1][j]=1;
                k[i][j]=0;
            }
            if(i<8&&i>=0&&j>0&&j<9&&(c[i][j]==c[i][j-1]&&c[i][j]==c[i][j+1])&&(c[i][j]==c[i+1][j]&&c[i][j]==c[i+2][j]))
            {
                q[i][j]=c[i][j]*111;
                score=score+200;
                ui->Score->display(score);
                k[i][j-1]=1;
                k[i][j+1]=1;
                k[i+1][j]=1;
                k[i+2][j]=1;
                k[i][j]=0;
            }
            if(i<=9&&i>1&&j>0&&j<9&&(c[i][j]==c[i][j-1]&&c[i][j]==c[i][j+1])&&(c[i][j]==c[i-1][j]&&c[i][j]==c[i-2][j]))
            {
                q[i][j]=c[i][j]*111;
                score=score+200;
                ui->Score->display(score);
                k[i][j-1]=1;
                k[i][j+1]=1;
                k[i-1][j]=1;
                k[i-2][j]=1;
                k[i][j]=0;
            }
            if(i<9&&i>0&&j>=0&&j<8&&(c[i][j]==c[i][j+1]&&c[i][j]==c[i][j+2])&&(c[i][j]==c[i-1][j]&&c[i][j]==c[i+1][j]))
            {
                q[i][j]=c[i][j]*111;
                score=score+200;
                ui->Score->display(score);
                k[i][j+1]=1;
                k[i][j+2]=1;
                k[i-1][j]=1;
                k[i+1][j]=1;
                k[i][j]=0;
            }
            if(i<9&&i>0&&j>1&&j<=9&&(c[i][j]==c[i][j-1]&&c[i][j]==c[i][j-2])&&(c[i][j]==c[i-1][j]&&c[i][j]==c[i+1][j]))
            {
                q[i][j]=c[i][j]*111;
                score=score+200;
                ui->Score->display(score);
                k[i][j-1]=1;
                k[i][j-2]=1;
                k[i-1][j]=1;
                k[i+1][j]=1;
                k[i][j]=0;
            }
            if(i>=0&&i<6&&c[i][j]==c[i+1][j]&&c[i][j]==c[i+2][j]&&c[i][j]==c[i+3][j]){
                special(i,j);
                if(i>=0&&i<=5&&c[i][j]==c[i+1][j]&&c[i][j]==c[i+2][j]&&c[i][j]==c[i+3][j]&&c[i][j]==c[i+4][j])
                {
                    q[i][j]=1000;
                    score=score+2000;
                    ui->Score->display(score);
                    k[i][j]=0;
                    k[i+2][j]=1;
                    k[i+1][j]=1;
                    k[i+3][j]=1;
                    k[i+4][j]=1;

                }
                else{
                    q[i][j]=c[i][j]*10+1;
                    score=score+120;
                    ui->Score->display(score);
                    k[i+3][j]=1;
                    k[i+2][j]=1;
                    k[i+1][j]=1;
                    k[i][j]=0;
                }

            }
            if(j>=0&&j<6&&c[i][j]==c[i][j+1]&&c[i][j]==c[i][j+2]&&c[i][j]==c[i][j+3]){
                special(i,j);
                if(j>=0&&j<=5&&c[i][j]==c[i][j+1]&&c[i][j]==c[i][j+2]&&c[i][j]==c[i][j+3]&&c[i][j]==c[i][j+4])
                {
                    q[i][j]=1000;
                    score=score+2000;
                    ui->Score->display(score);
                    k[i][j]=0;
                    k[i][j+2]=1;
                    k[i][j+1]=1;
                    k[i][j+3]=1;
                    k[i][j+4]=1;

                }
                else{
                    q[i][j]=c[i][j]*10+2;
                    score=score+120;
                    ui->Score->display(score);
                    k[i][j+3]=1;
                    k[i][j+2]=1;
                    k[i][j+1]=1;
                    k[i][j]=0;
                }
            }


//cout<<"qq[i+3][j]"<<i+3<<" "<<j<<" "<<q[i+3][j]<<endl;
//cout<<"qq[i][j+3]"<<i<<" "<<j+3<<" "<<q[i][j+3]<<endl;


        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(k[i][j]==1){
                special(i,j);
                q[i][j]=0;
                c[i][j]=0;
                score=score+20;
                ui->Score->display(score);
                picture();
                delay();
            }
        }
    }
    drop();
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(i>0&&i<9&&c[i][j]==c[i-1][j]&&c[i][j]==c[i+1][j]&&c[i][j]!=0)
                s++;
            if(j>0&&j<9&&c[i][j]==c[i][j-1]&&c[i][j]==c[i][j+1]&&c[i][j]!=0)
                s++;
        }
    }

    ui->Score->display(score);
    if(s!=0){
        remove();
    }
}

void MainWindow::move(int a)
{
    if(score>3000)
        ui->label_4->setPixmap(QPixmap(":/pics/star1.jpg"));
    if(score>5000)
        ui->label_6->setPixmap(QPixmap(":/pics/star1.jpg"));
    if(score>8000)
        ui->label_5->setPixmap(QPixmap(":/pics/star1.jpg"));
    if(score>10000)
        ui->win->setPixmap(QPixmap(":/pics/win.jpg"));
    else if(step<=0)
        ui->win->setPixmap(QPixmap(":/pics/lose.jpg"));
    int s=0;
    int b;
    int d;
    t++;

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(q[i][j]>100){
                c[i][j]=q[i][j]/100;
            }
            else if(q[i][j]>10){
                c[i][j]=q[i][j]/10;
            }
            else
                c[i][j]=q[i][j];
        }
    }


    if(t==1){
        ii=a/10;
        jj=a%10;
        t=-1;
        //p[ii][jj]->setIconSize(QSize(65,65));
        //p[ii][jj]->setFlat(false);
    }
    if(t==0){
        mm=a/10;
        nn=a%10;
        //p[mm][nn]->setIconSize(QSize(65,65));
        //p[mm][nn]->setFlat(false);
    }
    if(ii==mm||jj==nn){
    if((ii-mm)==1||(mm-ii)==1||(jj-nn)==1||(nn-jj)==1){


        b=q[ii][jj];
        q[ii][jj]=q[mm][nn];
        q[mm][nn]=b;
        d=c[ii][jj];
        c[ii][jj]=c[mm][nn];
        c[mm][nn]=d;
        picture();
        delay();
        step--;
        ui->Step->display(step);

        for(int i=0;i<10;i++){
             for(int j=0;j<10;j++){
                 if(i>0&&i<9&&c[i][j]==c[i-1][j]&&c[i][j]==c[i+1][j]&&c[i][j]!=0)
                     s++;
                 if(j>0&&j<9&&c[i][j]==c[i][j-1]&&c[i][j]==c[i][j+1]&&c[i][j]!=0)
                     s++;
                }
             }
          if(s==0){
              b=q[mm][nn];
              q[mm][nn]=q[ii][jj];
              q[ii][jj]=b;
              d=c[mm][nn];
              c[mm][nn]=c[ii][jj];
              c[ii][jj]=d;
              step++;
            }
           if(q[ii][jj]==1000)
               star(ii,jj,mm,nn);
           if(q[mm][nn]==1000)
               star(mm,nn,ii,jj);
        ii=jj=mm=nn=0;
        }


     }
    s=0;

    remove();
delay();
    drop();
    picture();

    //p[ii][jj]->setFlat(true);
    //p[mm][nn]->setFlat(true);
}
void MainWindow::drop()
{
    int w[10];
    for(int i=0;i<10;i++)
        w[i]=0;
    for(int j=0;j<10;j++){
        for(int i=9;i>0;i--){
            for(int k=i;k>0;k--){
                if(q[k][j]==0){
                    q[k][j]=q[k-1][j];
                    q[k-1][j]=0;
                    c[k][j]=c[k-1][j];
                    c[k-1][j]=0;

                }
            }
        }
    }
    for(int j=0;j<10;j++){
        for(int i=9;i>=0;i--){
            if(q[i][j]==0)
                w[j]++;
        }
    }
    for(int j=0;j<10;j++){
        for(int i=0;i<w[j];i++){
            q[i][j]=rand()%5+1;
            c[i][j]=q[i][j];

        }
    }
}
void MainWindow::delay()
{
    QTime dieTime= QTime::currentTime().addMSecs(50);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
MainWindow::~MainWindow()
{
    delete ui;
}
