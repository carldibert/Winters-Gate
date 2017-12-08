/***************************************************************
 * Name:      Winters_GateMain.h
 * Purpose:   Defines Application Frame
 * Author:    Carl Dibert ()
 * Created:   2017-11-10
 * Copyright: Carl Dibert ()
 * License:
 **************************************************************/

#ifndef WINTERS_GATEMAIN_H
#define WINTERS_GATEMAIN_H

//(*Headers(Winters_GateDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/listbox.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class Winters_GateDialog: public wxDialog
{
    public:

        Winters_GateDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~Winters_GateDialog();

    private:

        //(*Handlers(Winters_GateDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnLibrary_List_BoxSelect(wxCommandEvent& event);
        void PopulateListBox();
        //*)

        //(*Identifiers(Winters_GateDialog)
        static const long ID_LISTBOX2;
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON2;
        static const long ID_LISTBOX1;
        static const long ID_BUTTON1;
        //*)

        //(*Declarations(Winters_GateDialog)
        wxButton* Button1;
        wxStaticText* StaticText1;
        wxButton* Button2;
        wxListBox* ListBox2;
        wxListBox* ListBox1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // WINTERS_GATEMAIN_H
