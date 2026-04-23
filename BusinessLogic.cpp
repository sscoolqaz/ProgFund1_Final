#include "BusinessLogic.h"
#include "Project.h"
#include "stdafx.h"
#include <invitee.h>

struct GHWND {
  struct {
    int title;
    int first;
    int last;
    int suffix;
    int spouseTitle;
    int spouseLast;
    int spouseFirst;
    int children;
    int street;
    int city;
    int zip;
    int inviteeType;
    int eventState;
  } input;

  struct {
    int inStateInvitation;
    int inStateAnnouncement;
    int outStateInvitation;
    int outStateAnnouncement;
    int local;
    int distant;
  } lists;

  int button;
};

GHWND handle;

void InitializeGUI(HWND hWnd) {}

void ProcessInput() {}
