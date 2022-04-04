#ifndef canCOM_h
#define canCOM_h


#include <stdint.h>
#include "my_fp.h"
#include "params.h"
#include "stm32_can.h"
#include "calcCRC8.h"
#include "my_string.h"

class cancom
{ 
public:

 struct CanMsg
   {
      uint16_t id;
      uint32_t len;
      uint8_t data[8];

      //lets drag allong some more information...      
      uint8_t crcpresent;
      uint8_t crcbyte;
      uint8_t crcpoly;
      uint8_t crcoffset;
      uint8_t counterbyte;
      uint8_t counternible; //0=Lower 1=Upper
      uint8_t countermax=16;
      uint8_t lasttxcnt; //stores the last counter value between 2 sends
      //uint8_t mplexcycl; //stores the last variant code counter;
   };
 
 struct CanxBoot599{ //only first message
      uint8_t HWver;
      uint8_t SWver;
      uint16_t spare;
      uint16_t ID1;      
      uint16_t ID2;       
  };

  struct Canx599{
      uint8_t Inputs;
      uint8_t Outputs;
      uint16_t uint16_tPWM1;
      uint16_t uint16_tPWM2;      
      uint16_t uint16_tPWM3;       
  };

/* typedef enum {
	BMS_Unknown 	= 0,														//!< used by GUI
	BMS_Init  		= 1,														//!< init phase is assigning CID
	BMS_Config		= 2,														//!< config phase applies initial loading of registers
	BMS_Running    	= 3,														//!< bms is running
	BMS_Sleeping   	= 4,														//!< bms is sleeping
	BMS_Error      	= 5,														//!< error phase
	BMS_Idle        = 6, 														//!< BMS_Idle
	BMS_Off			= 7,														//!< BMS_Off
	BMS_ConfigMainCB	= 8,
	BMS_ConfigCellCB	= 9
}TYPE_BMS_STATUS; */

  struct Canx600{
      uint8_t  CID;                  //block # in order of daisy chain & ( NUMBER OF MODULES FOUND << 4 )
      uint8_t  BMSNum;               //#of string connected to the device & ( TYPE_BMS_STATUS << 4 );
      uint16_t uint16_tStackVoltage;
      uint16_t uint16_tTChip;       //miliKelvin / bit
      uint8_t  uint16_t2;       
  };
 
  struct Canx601{       
      uint16_t uint16_tCell1Voltage;
      uint16_t uint16_tCell2Voltage;      
      uint16_t uint16_tCell3Voltage;
      uint16_t uint16_tCell4Voltage;      
  };

  struct Canx602{      
      uint16_t uint16_tCell5Voltage;
      uint16_t uint16_tCell6Voltage;      
      uint32_t uint32_tCurrent;    //6ma / bit  
  };

  struct Canx603_1{      
      uint8_t  datamux; //=0x1;    
      uint8_t  spare;
      uint16_t uint16_tAN1Voltage;
      uint16_t uint16_tAN2Voltage;      
      uint16_t uint16_tAN3Voltage;
  };

  struct Canx603_2{      
      uint8_t  datamux; //=0x2;    
      uint8_t  spare; 
      uint16_t uint16_tAN4Voltage;
      uint16_t uint16_tAN5Voltage;
      uint16_t uint16_tAN6Voltage;  
  };

  struct Canx603_3{      
      uint8_t  datamux; //=0x3;    
      uint8_t  spare; 
      uint16_t uint16_tAN7Voltage;
      uint16_t uint16_tspare;
      uint16_t uint16_tspare2;  
  };

  struct Canx603_4{      
      uint8_t  datamux; //=0x4;
      uint8_t  uint8_CBStatus; //the CellBalanceSwitchStatus is only 6BITS    
      uint16_t uint16_tCCSamples;
      int32_t  int32_tCoulombCounter;      
   };

struct Canx603_5{      
      uint8_t  datamux; //=0x5;          
      uint8_t uint8_tAN1Voltage;
      uint8_t uint8_tAN2Voltage;      
      uint8_t uint8_tAN3Voltage;
      uint8_t uint8_tAN4Voltage;
      uint8_t uint8_tAN5Voltage;
      uint8_t uint8_tAN6Voltage;  
      uint8_t uint8_tAN7Voltage;
  };
  

  struct Canx604{      
      uint16_t uint16_tSpare;
      uint16_t uint16_tSpare2;      
      uint8_t uint8_tThresholdUVBITS; //under voltage
      uint8_t uint8_tThresholdOVBITS; //over voltage     
      uint8_t uint8_tThresholdUTBITS; //under Temperature     
      uint8_t uint8_tThresholdOTBITS; //over Temperature
  };

static void build_0x599(Canx599 *data);
static void build_0x600(Canx600 *data);
static void build_0x601(Canx601 *data);
static void build_0x602(Canx602 *data);
static void build_0x603(uint8_t *data);
static void build_0x604(Canx604 *data);

/* static void handle3B4(uint32_t data[2]);
static void handle272(uint32_t data[2]); */

static void InitMessages();

private:

static Can* can1;
static Can* can2;

//Needed logic functions
static void InitClass();
static void Send(CanMsg *msg);
static void Send(CanMsg *msg, Can* canport);
static void UpdateCounterAndCRC(CanMsg *cnmsg);
static void SendBootStruct();

//Project specific
static CanMsg CANMSG_Boot599;
static CanMsg CANMSG_0x599;
static CanMsg CANMSG_0x600;
static CanMsg CANMSG_0x601;
static CanMsg CANMSG_0x602;
static CanMsg CANMSG_0x603;
static CanMsg CANMSG_0x604;

//Lets generate all the function declarations for .h file...
//copy this part to the private class section.
static void init_0x599();
static void init_0x600();
static void init_0x601();
static void init_0x602();
static void init_0x603();
static void init_0x604();

};

#endif /* panameraCAN_h */