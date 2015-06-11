#ifndef MYLABEL
#define MYLABEL
#include <QLabel>
#include <QMouseEvent>

class myLabel: public QLabel
{

  public:
    myLabel()
    {
      this->setAlignment(Qt::AlignCenter);

      //Default Label Value
      this->setText("No Value");

      //set MouseTracking true to capture mouse event even its key is not pressed
      this->setMouseTracking(true);
    };
    ~ myLabel(){};

    void mousePressEvent ( QMouseEvent * event )
    {
      //Show x and y coordinate values of mouse cursor here
      if(event->buttons()==Qt::LeftButton)this->setText("X:"+QString::number(event->x())+"-- Y:"+QString::number(event->y())+"\nPressLeft");
      if(event->buttons()==Qt::RightButton)this->setText("X:"+QString::number(event->x())+"-- Y:"+QString::number(event->y())+"\nPressRight");
    };

};
#endif // MYLABEL

