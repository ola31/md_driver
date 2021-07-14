#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include "can_test/can.h"

#define GEAR_RATIO 30

#define LINEAR 0
#define ANGULAR 1

#define PI 3.141593

#define wheel_separation 0.470
#define wheel_radius 0.150

#define PID_VER 1            //CAN통신 주고받기 가능 여부 테스트 위한 것
#define PID_REQ_PID_DATA 4   //

#define PID_PNT_VEL_CMD 207
#define PID_MONITOR 196      //모터 1의 모니터데이터(위치정보:D4,5,6,7)
#define PID_MONITOR2 201     //모터 2의 모니터데이터

struct Encoder_data{
  int R_posi;
  int L_posi;
};

static int r_rpm_g,l_rpm_g;



class MD_driver : public CAN
{
  public:
    void initialize_md_driver(void);
    void send_RPM(short R_RPM, short L_RPM);
    struct Encoder_data read_Encoder(void);
    void Data_REQ(BYTE R_PID);
    void Encoder_REQ(void);
    void Torque_OFF(void);
    void contol_vel(float *cmd_vel);
    void Reset_ENC(void);
    int Byte2Int32(BYTE d4, BYTE d5, BYTE d6, BYTE d7);

};




#endif // MOTOR_DRIVER_H
