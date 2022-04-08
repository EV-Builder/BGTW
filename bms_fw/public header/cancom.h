#ifndef canCOM_h
#define canCOM_h

#include <stdint.h>

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
      uint8_t lasttxcnt; //stores the last counter value between 2 txes
      //uint8_t mplexcycl; //stores the last variant code counter;
   };
 
 struct CanxBoot599{ //only first message
      uint8_t HWver;
      uint8_t SWver;
      uint16_t spare;
      uint16_t ID1;      
      uint16_t ID2;       
  };

  struct Canx599_1{ //digIO
      uint8_t Mux;
      uint8_t Inputs;
      uint8_t Outputs;
      uint16_t uint16_tPWM1;
      uint16_t uint16_tPWM2;      
      uint8_t u8Spare;
  };

  struct Canx599_2{ //PWM
      uint8_t Mux;
      uint8_t Inputs;
      uint8_t Outputs;
      uint16_t uint16_tPWM1;
      uint16_t uint16_tPWM2;      
      uint8_t u8Spare;
  };

  struct Canx599_3{ //analog inputs?
      uint8_t Mux;
      uint8_t Inputs;
      uint8_t Outputs;
      uint16_t uint16_tPWM1;
      uint16_t uint16_tPWM2;      
      uint8_t u8Spare;
  };

    /* typedef enum {
        BMS_Unknown 	    = 0,														//!< used by GUI
        BMS_Init  		    = 1,														//!< init phase is assigning CID
        BMS_Config		    = 2,														//!< config phase applies initial loading of registers
        BMS_Running    	    = 3,														//!< bms is running
        BMS_Sleeping   	    = 4,														//!< bms is sleeping
        BMS_Error      	    = 5,														//!< error phase
        BMS_Idle            = 6, 														//!< BMS_Idle
        BMS_Off			    = 7,														//!< BMS_Off
        BMS_ConfigMainCB	= 8,
        BMS_ConfigCellCB	= 9
    }TYPE_BMS_STATUS; */

  struct Canx600{
      uint8_t  CID;                  //block # in order of daisy chain & ( NUMBER OF MODULES FOUND << 4 )
      uint8_t  BMSNum;               //#of string connected to the device & ( TYPE_BMS_STATUS << 4 );
      uint16_t uint16_tStackVoltage;
      uint16_t uint16_tTChip;       //miliKelvin / bit
      uint16_t uint16_SysCfg1;       
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
      uint16_t uint16_tCell7Voltage;
      uint16_t uint16_tCell8Voltage;  
  };
  
  struct Canx603{      
      uint16_t uint16_tCell9Voltage;
      uint16_t uint16_tCell10Voltage;      
      uint16_t uint16_tCell11Voltage;
      uint16_t uint16_tCell12Voltage;  
  };

  struct Canx604_1{      
      uint8_t  datamux; //=0x1;    
      uint8_t  spare;
      uint16_t uint16_tAN1Voltage;
      uint16_t uint16_tAN2Voltage;      
      uint16_t uint16_tAN3Voltage;
  };

  struct Canx604_2{      
      uint8_t  datamux; //=0x2;    
      uint8_t  spare; 
      uint16_t uint16_tAN4Voltage;
      uint16_t uint16_tAN5Voltage;
      uint16_t uint16_tAN6Voltage;  
  };

  struct Canx604_3{      
      uint8_t  datamux; //=0x3;    
      uint8_t  spare; 
      uint16_t uint16_tAN7Voltage;
      uint16_t uint16_tspare;
      uint16_t uint16_tspare2;  
  };

  struct Canx604_4{      
      uint8_t  datamux; //=0x4;
      uint8_t  uint8_CBStatus; //the CellBalanceSwitchStatus is only 6BITS    
      uint16_t uint16_tCCSamples;
      int32_t  int32_tCoulombCounter;      
   };

struct Canx604_5{      //temperatures
      uint8_t  datamux; //=0x5;          
      int8_t int8_tAN1Temperature;
      int8_t int8_tAN2Temperature;      
      int8_t int8_tAN3Temperature;
      int8_t int8_tAN4Temperature;
      int8_t int8_tAN5Temperature;
      int8_t int8_tAN6Temperature;  
      int8_t int8_tAN7Temperature;
  };
  

  struct Canx605{      
      uint16_t uint16_tSpare;
      uint16_t uint16_tSpare2;      
      uint8_t uint8_tThresholdUVBITS; //under voltage
      uint8_t uint8_tThresholdOVBITS; //over voltage     
      uint8_t uint8_tThresholdUTBITS; //under Temperature     
      uint8_t uint8_tThresholdOTBITS; //over Temperature
  };

private:

};

#endif /* canCOM_h */