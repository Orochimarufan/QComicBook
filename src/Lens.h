#ifndef __LENS_H
#define __LENS_H

#include <QGraphicsItem>

class QPixmap;
class QTime;

namespace QComicBook
{
    class Lens: public QGraphicsItem
    {
    public:
        Lens();
        ~Lens();

        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *opt, QWidget *widget = 0);

    protected:
        QVariant itemChange(GraphicsItemChange change, const QVariant &value);

    private:
        QPixmap *m_pixmap;
        QTime *m_time;
    };
}

#endif
