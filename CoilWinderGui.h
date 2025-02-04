#include "MCUFRIEND_kbv.h"
#include "TouchScreen.h"
#include "BobbinDriver.h"

#ifndef _COILWINDERGUI_H
#define _COILWINDERGUI_H

enum TouchArea {
    Miss,
    Cancel,
    Coils,
    Down,
    Okay,
    Rotations,
    Up,
};

class CoilWinderGui {
    public:
        // constructor
        CoilWinderGui(BobbinDriver *bobbinDriver);
        
        // methods
        void start();
        TouchArea getTouchArea(TSPoint *p);
        uint8_t getDesiredRotations();
        void onCoilsFieldPress();
        void onRotationsFieldPress();
        void onUpBtnPress();
        void onDownBtnPress();
        void onCancelBtnPress();
        void onOkayBtnPress();

    private:
        // fields
        MCUFRIEND_kbv m_tft;
        TouchArea m_highlightedArea;
        uint16_t m_coilCount;
        uint16_t m_rotationCount;
        BobbinDriver *m_bobbinDriver;

        // methods
        void drawCancelButton();
        void drawOkayButton();
        void drawCoilField();
        void drawRotationField();
        void drawUpButton();
        void drawDownButton();
        double getDistance(int16_t x0, int16_t y0, int16_t x1, int16_t y1);
};

#endif // _COILWINDERGUI_H