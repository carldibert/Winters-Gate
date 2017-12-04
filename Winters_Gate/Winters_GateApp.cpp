/***************************************************************
 * Name:      Winters_GateApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Carl Dibert ()
 * Created:   2017-11-10
 * Copyright: Carl Dibert ()
 * License:
 **************************************************************/

#include "Winters_GateApp.h"

//(*AppHeaders
#include "Winters_GateMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Winters_GateApp);

bool Winters_GateApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Winters_GateDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
