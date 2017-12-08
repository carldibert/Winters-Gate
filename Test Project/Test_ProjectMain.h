/***************************************************************
 * Name:      Test_ProjectMain.h
 * Purpose:   Defines Application Frame
 * Author:    Carl Dibert ()
 * Created:   2017-12-07
 * Copyright: Carl Dibert ()
 * License:
 **************************************************************/

#ifndef TEST_PROJECTMAIN_H
#define TEST_PROJECTMAIN_H

//(*Headers(Test_ProjectDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class Test_ProjectDialog: public wxDialog
{
    public:

        Test_ProjectDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~Test_ProjectDialog();

    private:

        //(*Handlers(Test_ProjectDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(Test_ProjectDialog)
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON1;
        static const long ID_STATICLINE1;
        static const long ID_BUTTON2;
        static const long ID_STATICTEXT2;
        //*)

        //(*Declarations(Test_ProjectDialog)
        wxStaticText* StaticText2;
        wxButton* Button1;
        wxStaticText* StaticText1;
        wxBoxSizer* BoxSizer2;
        wxButton* Button2;
        wxStaticLine* StaticLine1;
        wxBoxSizer* BoxSizer1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // TEST_PROJECTMAIN_H
