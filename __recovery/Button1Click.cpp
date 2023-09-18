#define MBN_VARARG

#include "mbn.h"
#include "MeeteringForm.h"
#include "Button1Click.h"


void __fastcall TForm1::Button1Click(TObject *Sender)
{
	OnlineDetectTimer->Enabled = true;

//	for (int i = 0; i < Form1->ControlCount ; i++)
//	{
//		// disable the control by setting Enabled property to false
//		Form1->Controls[i]->Enabled = true;
//	}






	int cnt;
	int cntvu_busses;
	struct mbn_interface *itf;
	char error[MBN_ERRSIZE];

	char Temp[16];
	//char *url;
	//char *port_found;
	char url[256];
	char port[16];
	char obj_desc[32];
	struct mbn_node_info thisnodeB;
	int cntSwitch;
	struct mbn_object objects[370];
	//struct mbn_object objects[350];
	int cntObject = 0;



	String s = UDPEdit->Text;



	StrPCopy(Temp, s);


  // itf = mbnUDPOpen(Temp, strdup("34848"), 0, error);  // Maak verbinding met ethernet  // strdup( ) handige functie
   itf = mbnUDPOpen(Temp, strdup("34848"), 0, error);

   //
//
//
//
	if( itf == 0 )
	{
		//memLog->Lines->Add( "EthernetOpen failed: %s" );
		ShowMessage("Welcome to the Sellers Bank.");
		return;
	}

	thisnodeB.MambaNetAddr = 0;
	thisnodeB.Services = 0;
	sprintf(thisnodeB.Description, "Axite Control Surface 6 Faders + CRM");
	sprintf(thisnodeB.Name, "Meetering Test Node");
	thisnodeB.ManufacturerID = 0x0001;
	thisnodeB.ProductID = 0x0024;
	thisnodeB.UniqueIDPerProduct = 0x516;   //UniqueIDPerProduct
	thisnodeB.HardwareMajorRevision = 0;
	thisnodeB.HardwareMinorRevision = 0;
	thisnodeB.FirmwareMajorRevision = 1;
	thisnodeB.FirmwareMinorRevision = 3;
	thisnodeB.FPGAFirmwareMajorRevision = 0;
	thisnodeB.FPGAFirmwareMinorRevision = 0;
	thisnodeB.NumberOfObjects = 0;
	thisnodeB.DefaultEngineAddr = 0;
	thisnodeB.HardwareParent[0] = 0;
	thisnodeB.HardwareParent[1] = 0;
	thisnodeB.HardwareParent[2] = 0;
	thisnodeB.ServiceRequest = 0;









  objects[cntObject++] = MBN_OBJ( (char *)"Meter 1 Left dB",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_FLOAT, 2, -50.0, 5.0, -50.0, -50.0);
  objects[cntObject++] = MBN_OBJ( (char *)"Meter 1 Right dB",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_FLOAT, 2, -50.0, 5.0, -50.0, -50.0);
  objects[cntObject++] = MBN_OBJ( (char *)"Phase Meter 1",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_FLOAT, 2, 0.0, 2.0, 0.0, 0.0);
  objects[cntObject++] = MBN_OBJ( (char *)"Meter 1 Label A",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_OCTETS, 8, 0, 127, 20, "Mon. 1");
  objects[cntObject++] = MBN_OBJ( (char *)"Meter 1 Label B",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_OCTETS, 8, 0, 127, 20, "-");
  objects[cntObject++] = MBN_OBJ( (char *)"Meter 2 Left dB",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_FLOAT, 2, -50.0, 5.0, -50.0, -50.0);
  objects[cntObject++] = MBN_OBJ( (char *)"Meter 2 Right dB",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_FLOAT, 2, -50.0, 5.0, -50.0, -50.0);
  objects[cntObject++] = MBN_OBJ( (char *)"Phase Meter 2",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_FLOAT, 2, 0.0, 2.0, 0.0, 0.0);
  objects[cntObject++] = MBN_OBJ( (char *)"Meter 2 Label A",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_OCTETS, 8, 0, 127, 20, "Mon. 2");
  objects[cntObject++] = MBN_OBJ( (char *)"Meter 2 Label B",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_OCTETS, 8, 0, 127, 20, "-");
  objects[cntObject++] = MBN_OBJ( (char *)"Meter 3 Left dB",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_FLOAT, 2, -50.0, 5.0, -50.0, -50.0);
  objects[cntObject++] = MBN_OBJ( (char *)"Meter 3 Right dB",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_FLOAT, 2, -50.0, 5.0, -50.0, -50.0);
  objects[cntObject++] = MBN_OBJ( (char *)"Meter 3 Label",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_OCTETS, 8, 0, 127, 20, "Mon. 2");
  objects[cntObject++] = MBN_OBJ( (char *)"Meter 4 Left dB",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_FLOAT, 2, -50.0, 5.0, -50.0, -50.0);
  objects[cntObject++] = MBN_OBJ( (char *)"Meter 4 Right dB",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_FLOAT, 2, -50.0, 5.0, -50.0, -50.0);
  objects[cntObject++] = MBN_OBJ( (char *)"Meter 4 Label",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_OCTETS, 8, 0, 127, 20, "Mon. 2");
  objects[cntObject++] = MBN_OBJ( (char *)"Main/Clock Label",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_OCTETS, 8, 0, 127, 20, "Mon. 2");
  objects[cntObject++] = MBN_OBJ( (char *)"Redlight 1",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
  objects[cntObject++] = MBN_OBJ( (char *)"Redlight 2",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
  objects[cntObject++] = MBN_OBJ( (char *)"Redlight 3",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
  objects[cntObject++] = MBN_OBJ( (char *)"Redlight 4",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
  objects[cntObject++] = MBN_OBJ( (char *)"Redlight 5",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
  objects[cntObject++] = MBN_OBJ( (char *)"Redlight 6",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
  objects[cntObject++] = MBN_OBJ( (char *)"Redlight 7",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
  objects[cntObject++] = MBN_OBJ( (char *)"Redlight 8",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
  objects[cntObject++] = MBN_OBJ( (char *)"Second dot count down",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
  objects[cntObject++] = MBN_OBJ( (char *)"Program end time enable",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
  objects[cntObject++] = MBN_OBJ( (char *)"Program end hour",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_UINT, 1, 0, 59, 0, 0);
  objects[cntObject++] = MBN_OBJ( (char *)"Program end minute",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_UINT, 1, 0, 59, 0, 0);
  objects[cntObject++] = MBN_OBJ( (char *)"Program end second",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_UINT, 1, 0, 59, 0, 0);
  objects[cntObject++] = MBN_OBJ( (char *)"Count down seconds",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_FLOAT, 2, 0.0, 60.0, 0.0, 0.0);
//Module Label
  objects[cntObject++] = MBN_OBJ( (char *)"Module label",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_OCTETS, 8, 0, 127, 20, "Mod 1");
//Module Source label
  objects[cntObject++] = MBN_OBJ( (char *)"Module source label",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_OCTETS, 8, 0, 127, 20, "None");
//Module Console
  objects[cntObject++] = MBN_OBJ( (char *)"Module console",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_UINT, 1, 0, 255, 0, 0);
//Module Meter Left
//Module Meter Right
  objects[cntObject++] = MBN_OBJ( (char *)"Module Meter Left dB",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_FLOAT, 2, -50.0, 5.0, -50.0, -50.0);
  objects[cntObject++] = MBN_OBJ( (char *)"Module Meter Right dB",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_FLOAT, 2, -50.0, 5.0, -50.0, -50.0);
//DSP Gain
  objects[cntObject++] = MBN_OBJ( (char *)"DSP gain",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_OCTETS, 8, 0, 127, 20, "0 dB");
//LC On/Off
  objects[cntObject++] = MBN_OBJ( (char *)"LC on/off",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
//LC Freq
  objects[cntObject++] = MBN_OBJ( (char *)"LC frequency",
                                   MBN_DATATYPE_NODATA,
                                   MBN_DATATYPE_UINT, 2, 10, 20000, 80, 80);
//Dyn On/Off
  objects[cntObject++] = MBN_OBJ( (char *)"Dyn on/off",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
//DExp Th
  objects[cntObject++] = MBN_OBJ( (char *)"D-Exp threshold",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_OCTETS, 8, 0, 127, 20, "-20 dB");
//AGC Th
  objects[cntObject++] = MBN_OBJ( (char *)"AGC threshold",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_OCTETS, 8, 0, 127, 20, "-10 dB");
//AGC Ratio
  objects[cntObject++] = MBN_OBJ( (char *)"AGC Ratio",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_OCTETS, 8, 0, 127, 20, "100%");
  objects[cntObject++] = MBN_OBJ( (char *)"EQ on/off",
                                  MBN_DATATYPE_STATE, 1, 1, 0, 1, 0,
                                  MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
  for (int cntBand=0; cntBand<6; cntBand++)
  {
    sprintf(obj_desc, "EQ%d level", cntBand+1);
    objects[cntObject++] = MBN_OBJ(obj_desc,
                                   MBN_DATATYPE_FLOAT, 1, 2, -18.0, 18.0, 0.0,
                                   MBN_DATATYPE_FLOAT, 2, -18.0, 18.0, 0.0, 0.0);
    sprintf(obj_desc, "EQ%d frequency", cntBand+1);
    objects[cntObject++] = MBN_OBJ(obj_desc,
                                   MBN_DATATYPE_UINT, 1, 2, 10, 20000, 1000,
                                   MBN_DATATYPE_UINT, 2, 10, 20000, 1000, 1000);
    sprintf(obj_desc, "EQ%d Q", cntBand+1);
    objects[cntObject++] = MBN_OBJ(obj_desc,
                                   MBN_DATATYPE_FLOAT, 1, 2, 0.1, 10.0, 1.0,
                                   MBN_DATATYPE_FLOAT, 2, 0.1, 10.0, 1.0, 1.0);
    sprintf(obj_desc, "EQ%d type", cntBand+1);
    objects[cntObject++] = MBN_OBJ(obj_desc,
                                   MBN_DATATYPE_STATE, 1, 2, 0, 7, 3,
                                   MBN_DATATYPE_STATE, 2, 0, 7, 3);
  }
  objects[cntObject++] = MBN_OBJ( (char *)"Panorama",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_UINT, 2, 0, 1023, 512, 512);
  objects[cntObject++] = MBN_OBJ( (char *)"Show module parameters",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
  objects[cntObject++] = MBN_OBJ( (char *)"MIC active timer",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
  objects[cntObject++] = MBN_OBJ( (char *)"Init progress",
                                  MBN_DATATYPE_NODATA,
                                  MBN_DATATYPE_UINT, 1, 0, 100, 0, 0);

  for (int cntModule=0; cntModule<32; cntModule++)
  {
    sprintf(obj_desc, "Small meter %d left dB", cntModule+1);
    objects[cntObject++] = MBN_OBJ( obj_desc,
                                    MBN_DATATYPE_NODATA,
                                    MBN_DATATYPE_FLOAT, 2, -50.0, 5.0, -50.0, -50.0);
    sprintf(obj_desc, "Small meter %d right dB", cntModule+1);
    objects[cntObject++] = MBN_OBJ( obj_desc,
                                    MBN_DATATYPE_NODATA,
                                    MBN_DATATYPE_FLOAT, 2, -50.0, 5.0, -50.0, -50.0);
  }











































































	// 1024 - 1035: OLED Display lines

//
//	sprintf(obj_desc, "Meter %d Left dB", cnt+1);
//	objects[cntObject++] = MBN_OBJ( obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_FLOAT, 2, -50.0, 5.0, -50.0, -50.0);
//	sprintf(obj_desc, "Meter %d Right dB", cnt+1);
//	objects[cntObject++] = MBN_OBJ( obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_FLOAT, 2, -50.0, 5.0, -50.0, -50.0);
//
//
//
//	sprintf(obj_desc, "Phase Meter %d", cnt+1);
//	objects[cntObject++] = MBN_OBJ( obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_FLOAT, 2, 0.0, 0.0, 0.0, 0.0);
//
//	sprintf(obj_desc, "Display %d Label A", cnt+1);
//	objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_OCTETS, 8, 0, 127, 0, "");
//
//	sprintf(obj_desc, "Display %d Label B", cnt+1);
//	objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_OCTETS, 8, 0, 127, 0, "");
//
//	sprintf(obj_desc, "dummy %d", cnt+1);
//	objects[cntObject++] = MBN_OBJ( obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_FLOAT, 2, 0.0, 0.0, 0.0, 0.0);
//
//	for (cnt=0; cnt<66; cnt++)
//	{
//		sprintf(obj_desc, "dummy %d", cnt+1);
//		objects[cntObject++] = MBN_OBJ( obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_FLOAT, 2, 0.0, 0.0, 0.0, 0.0);
//	}
//
//
//	// 1036 - 1047: Stereo Audio level metering
//	for (cnt=0; cnt<32; cnt++)
//	{
//		sprintf(obj_desc, "Small meter %d left dB", cnt+1);
//		objects[cntObject++] = MBN_OBJ( obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_FLOAT, 2, -50.0, 5.0, -50.0, -50.0);
//		sprintf(obj_desc, "Small meter %d right dB", cnt+1);
//		objects[cntObject++] = MBN_OBJ( obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_FLOAT, 2, -50.0, 5.0, -50.0, -50.0);
//	}



	// // //------------------------------------------------------------------------------------------------
	thisnodeB.NumberOfObjects = cntObject;
	mbn = mbnInit(&thisnodeB, objects, itf, error);

//	if((mbn = mbnInit(&thisnodeB, objects, itf, error)) == 0)
//	{
//		return; // memLog(LF_APP, "Init failed: %s", error);
//	}

	// Callbacks
   //	mbnSetSensorDataChangedCallback(mbn, mSensorDataChanged);
	mbnSetSetActuatorDataCallback(mbn, mSetActuatorData);
	mbnSetOnlineStatusCallback(mbn, mOnlineStatus);



	//mbnSetErrorCallback(mbn, mError);



	mbnStartInterface(itf, error);

	//lstInterfaces->Enabled = false;
	UDPEdit->Enabled = false;
	//TCPEdit->Enabled = false;
	//cseUniqueID->Enabled = false;
	//btnOpen->Enabled = false;
	//btnClose->Enabled = true;

	mbnSendPingRequest(mbn, MBN_BROADCAST_ADDRESS);


}
//---------------------------------------------------------------------------


