/* 
 * File:   qei1.h
 * Author: Fernando
 *
 * Created on Mar 22, 2019, 9:54 AM
 */

#ifndef QEI1_H
#define	QEI1_H

void QEI1_Initialize(void);
void QEI1_PosCounter32BitSet(uint32_t value);
uint32_t QEI1_PosCounter32BitGet(void);
int32_t QEI1_PosCounter32BitSgnGet(void);
uint32_t QEI1_PosCounter32BitGetX1(void);
int32_t QEI1_PosCounter32BitSgnGetX1(void);

#endif	/* QEI1_H */