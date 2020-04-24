#include "xc.h"
#include "qei1.h"

void QEI1_Initialize(void) {
    __builtin_write_OSCCONL(OSCCON & 0xbf); // unlock PPS
    RPINR14bits.QEA1R = 72;
    RPINR14bits.QEB1R = 58;
    __builtin_write_OSCCONL(OSCCON | 0x40); // lock   PPS

    PMD3bits.PMPMD = 1;
    PMD1bits.QEI1MD = 0;

    QEI1CONbits.QEIEN = 0; // Disable QEI Module
    QEI1CONbits.IMV = 0b00; // Index input event does not affect position counter
    QEI1CONbits.QEISIDL = 1; // Discontinue module operation when device enters Idle mode
    QEI1CONbits.INTDIV = 0b000; // 1:1 prescale value
    QEI1CONbits.PIMOD = 0b000; // Index input event does not affect position counter
    QEI1CONbits.CNTPOL = 1; // Counter direction is negative unless modified by external Up/Down signal
    QEI1CONbits.GATEN = 0; // External gate signal does not affect position counter/timer operation
    QEI1CONbits.CCM = 0b00; // Quadrature Encoder mode

    QEI1IOCbits.FLTREN = 1; // Input Pin Digital filter is enabled
    QEI1IOCbits.QFDIV = 0b010; // 1:4 clock divide
    QEI1IOCbits.OUTFNC = 0b00; // Output is disabled
    QEI1IOCbits.SWPAB = 0; // QEAx and QEBx are not swapped
    QEI1IOCbits.HOMPOL = 0; // Input is not inverted
    QEI1IOCbits.IDXPOL = 0; // Input is not inverted
    QEI1IOCbits.QEAPOL = 0; // Input is not inverted
    QEI1IOCbits.QEBPOL = 0; // Input is not inverted
    QEI1IOCbits.QCAPEN = 1; // HOMEx input event (positive edge) does not trigger a position capture event

    QEI1STAT = 0;
    QEI1LECL = 0;
    QEI1LECH = 0;
    QEI1GECH = 0;
    POS1HLD = 0;
    VEL1CNT = 0;

    INDX1CNTH = 0;
    INDX1CNTL = 0;

    POS1HLD = 0;
    POS1CNTL = 0;

    QEI1CONbits.QEIEN = 1; // Enable QEI Module
}

void QEI1_PosCounter32BitSet(uint32_t value) {
    /* Update the counter values */
    POS1HLD = ((value & 0xFFFF0000) >> 16);
    POS1CNTL = (value & 0x0000FFFF);
}

uint32_t QEI1_PosCounter32BitGet(void) {
    uint32_t countVal = 0xFFFFFFFF;
    uint16_t countValUpper;
    uint16_t countValLower;

    countValLower = POS1CNTL;
    countValUpper = POS1HLD;

    /* get the current counter value and return it */
    countVal = (((uint32_t) countValUpper << 16) | countValLower);

    return ( countVal);
}

int32_t QEI1_PosCounter32BitSgnGet(void) {
    uint32_t countVal = 0xFFFFFFFF;
    uint16_t countValUpper;
    uint16_t countValLower;

    countValLower = POS1CNTL;
    countValUpper = POS1HLD;

    /* get the current counter value and return it */
    countVal = (((uint32_t) countValUpper << 16) | countValLower);

    return ( countVal);
}

uint32_t QEI1_PosCounter32BitGetX1(void) {
    uint32_t countVal = 0xFFFFFFFF;

    /* get the current counter value and return it */
    countVal = QEI1_PosCounter32BitGet() >> 2;

    return ( countVal);
}

int32_t QEI1_PosCounter32BitSgnGetX1(void) {
    uint32_t countVal = 0xFFFFFFFF;

    /* get the current counter value and return it */
    countVal = QEI1_PosCounter32BitSgnGet() >> 2;

    return ( countVal);
}
