/***************************************************************
 * Name:      Test_ProjectApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Carl Dibert ()
 * Created:   2017-12-07
 * Copyright: Carl Dibert ()
 * License:
 **************************************************************/

#include "Test_ProjectApp.h"

//(*AppHeaders
#include "Test_ProjectMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Test_ProjectApp);

bool Test_ProjectApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Test_ProjectDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
