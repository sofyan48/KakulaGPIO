#include "kakulagpio.h"
#include "ui_kakulagpio.h"
#include "GPIOClass.h"

KakulaGpio::KakulaGpio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KakulaGpio)
{
    ui->setupUi(this);

    gong1 = new Gong;
    gong2 = new Gong;
    gong3 = new Gong;
    gong4 = new Gong;
    gong5 = new Gong;
    gong6 = new Gong;
    gong7 = new Gong;


    GPIOClass *pushGong1 = new GPIOClass("12");
    GPIOClass *pushGong2 = new GPIOClass("13");
    GPIOClass *pushGong3 = new GPIOClass("16");
    GPIOClass *pushGong4 = new GPIOClass("19");
    GPIOClass *pushGong5 = new GPIOClass("20");
    GPIOClass *pushGong6 = new GPIOClass("26");
    GPIOClass *pushGong7 = new GPIOClass("21");

    pushGong1->setdir_gpio("in");\
    pushGong2->setdir_gpio("in");
    pushGong3->setdir_gpio("in");
    pushGong4->setdir_gpio("in");
    pushGong5->setdir_gpio("in");
    pushGong6->setdir_gpio("in");
    pushGong7->setdir_gpio("in");

    string inputState1;
    string inputState2;
    string inputState3;
    string inputState4;
    string inputState5;
    string inputState6;
    string inputState7;
    int i;
       while(i < 20)
       {
           usleep(500000);  // wait for 0.5 seconds
           pushGong1->getval_gpio(inputState1); //read state of GPIO17 input pin
           if(inputState1 == "0") // if input pin is at state "0" i.e. button pressed
           {
               cout << "input pin state is \"Pressed \".n Will check input pin state again in 20ms "<<endl;
                   usleep(20000);
                       cout << "Checking again ....." << endl;
                       pushGong1->getval_gpio(inputState1); // checking again to ensure that state "0" is due to button press and not noise
               if(inputState1 == "0")
               {
                   cout << " Waiting until pin is unpressed....." << endl;
                   while (inputState1 == "0"){
                   pushGong1->getval_gpio(inputState1);
                   };
                   cout << "pin is unpressed" << endl;

               }
               else
                   cout << "input pin state is definitely \"UnPressed\". That was just noise." <<endl;

           }
           i++;
       }

}

KakulaGpio::~KakulaGpio()
{
    delete ui;
}

void KakulaGpio::clickedGong(QString type)
{

    this->gong1->setPath("bunyi");
    this->gong1->setSound("a1.ogg",type);
    this->gong1->setVolume(100);
    this->gong1->play();
}

void KakulaGpio::clickedGong2(QString type)
{
    this->gong2->setPath("bunyi");
    this->gong2->setSound("a2.ogg",type);
    this->gong2->setVolume(100);
    this->gong2->play();
}

void KakulaGpio::clickedGong3(QString type)
{
    this->gong3->setPath("bunyi");
    this->gong3->setSound("a3.ogg",type);
    this->gong3->setVolume(100);
    this->gong3->play();
}

void KakulaGpio::clickedGong4(QString type)
{
    this->gong4->setPath("bunyi");
    this->gong4->setSound("a4.ogg",type);
    this->gong4->setVolume(100);
    this->gong4->play();
}

void KakulaGpio::clickedGong5(QString type)
{
    this->gong5->setPath("bunyi");
    this->gong5->setSound("a5.ogg",type);
    this->gong5->setVolume(100);
    this->gong5->play();
}

void KakulaGpio::clickedGong6(QString type)
{
    this->gong6->setPath("bunyi");
    this->gong6->setSound("a6.ogg",type);
    this->gong6->setVolume(100);
    this->gong6->play();
}

void KakulaGpio::clickedGong7(QString type)
{
    this->gong7->setPath("bunyi");
    this->gong7->setSound("a7.ogg",type);
    this->gong7->setVolume(100);
    this->gong7->play();
}

