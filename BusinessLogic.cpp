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
    int state;
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

int getHandle(int someGroup) {
  switch (someGroup) {
  case 0:
    return handle.lists.inStateInvitation;
  case 1:
    return handle.lists.inStateAnnouncement;
  case 2:
    return handle.lists.outStateInvitation;
  case 3:
    return handle.lists.outStateAnnouncement;
  case 4:
    return handle.lists.local;
  case 5:
    return handle.lists.distant;
  }
  return -1;
}

void InitializeGUI(HWND hWnd) {
  int labelX = 20;
  int inputX = 160;
  int inputW = 250;
  int rowSpace = 30;
  int y = 20;

  CreateLabel(hWnd, "Title:", labelX, y, 130, 20);
  handle.input.title =
      CreateTextBox(hWnd, inputX, y, inputW, 20, true, false, false);
  y += rowSpace;

  CreateLabel(hWnd, "First Name:", labelX, y, 130, 20);
  handle.input.first =
      CreateTextBox(hWnd, inputX, y, inputW, 20, true, false, false);
  y += rowSpace;

  CreateLabel(hWnd, "Last Name*:", labelX, y, 130, 20);
  handle.input.last =
      CreateTextBox(hWnd, inputX, y, inputW, 20, true, false, false);
  y += rowSpace;

  CreateLabel(hWnd, "Suffix:", labelX, y, 130, 20);
  handle.input.suffix =
      CreateTextBox(hWnd, inputX, y, inputW, 20, true, false, false);
  y += rowSpace;

  CreateLabel(hWnd, "Spouse Title:", labelX, y, 130, 20);
  handle.input.spouseTitle =
      CreateTextBox(hWnd, inputX, y, inputW, 20, true, false, false);
  y += rowSpace;

  CreateLabel(hWnd, "Spouse First:", labelX, y, 130, 20);
  handle.input.spouseFirst =
      CreateTextBox(hWnd, inputX, y, inputW, 20, true, false, false);
  y += rowSpace;

  CreateLabel(hWnd, "Spouse Last:", labelX, y, 130, 20);
  handle.input.spouseLast =
      CreateTextBox(hWnd, inputX, y, inputW, 20, true, false, false);
  y += rowSpace;

  CreateLabel(hWnd, "Children:", labelX, y, 130, 20);
  handle.input.children =
      CreateTextBox(hWnd, inputX, y, inputW, 20, true, false, false);
  y += rowSpace;

  CreateLabel(hWnd, "Street Address*:", labelX, y, 130, 20);
  handle.input.street =
      CreateTextBox(hWnd, inputX, y, inputW, 20, true, false, false);
  y += rowSpace;

  CreateLabel(hWnd, "City*:", labelX, y, 130, 20);
  handle.input.city =
      CreateTextBox(hWnd, inputX, y, inputW, 20, true, false, false);
  y += rowSpace;

  CreateLabel(hWnd, "State*:", labelX, y, 130, 20);
  handle.input.state =
      CreateTextBox(hWnd, inputX, y, inputW, 20, true, false, false);
  y += rowSpace;

  CreateLabel(hWnd, "Zip*:", labelX, y, 130, 20);
  handle.input.zip =
      CreateTextBox(hWnd, inputX, y, inputW, 20, true, false, false);
  y += rowSpace;

  CreateLabel(hWnd, "Invitee Type:", labelX, y, 130, 20);
  handle.input.inviteeType =
      CreateTextBox(hWnd, inputX, y, inputW, 20, true, false, false);
  y += rowSpace;

  CreateLabel(hWnd, "Event State*:", labelX, y, 130, 20);
  handle.input.eventState =
      CreateTextBox(hWnd, inputX, y, inputW, 20, true, false, false);
  y += rowSpace;

  handle.button = CreateButton(hWnd, "Submit", labelX, y, 100, 30);

  int outX = 450, outY = 20, outW = 400, outH = 150, outGap = 170;

  CreateLabel(hWnd, "In-State Invitations:", outX, outY, 200, 20);
  handle.lists.inStateInvitation =
      CreateTextBox(hWnd, outX, outY + 20, outW, outH, false, true, false);

  CreateLabel(hWnd, "In-State Announcements:", outX, outY + outGap, 200, 20);
  handle.lists.inStateAnnouncement = CreateTextBox(
      hWnd, outX, outY + outGap + 20, outW, outH, false, true, false);

  CreateLabel(hWnd, "Out-of-State Invitations:", outX, outY + outGap * 2, 200,
              20);
  handle.lists.outStateInvitation = CreateTextBox(
      hWnd, outX, outY + outGap * 2 + 20, outW, outH, false, true, false);

  CreateLabel(hWnd, "Out-of-State Announcements:", outX, outY + outGap * 3, 200,
              20);
  handle.lists.outStateAnnouncement = CreateTextBox(
      hWnd, outX, outY + outGap * 3 + 20, outW, outH, false, true, false);

  CreateLabel(hWnd, "Local:", outX, outY + outGap * 4, 200, 20);
  handle.lists.local = CreateTextBox(hWnd, outX, outY + outGap * 4 + 20, outW,
                                     outH, false, true, false);

  CreateLabel(hWnd, "Distant:", outX, outY + outGap * 5, 200, 20);
  handle.lists.distant = CreateTextBox(hWnd, outX, outY + outGap * 5 + 20, outW,
                                       outH, false, true, false);
}

void ProcessInput() {

  inv::ParticipantClass invitee;
  if (!invitee.setInvitee(ReadStringFromTextBox(handle.input.title),
                          ReadStringFromTextBox(handle.input.first),
                          ReadStringFromTextBox(handle.input.last),
                          ReadStringFromTextBox(handle.input.suffix),
                          ReadStringFromTextBox(handle.input.spouseTitle),
                          ReadStringFromTextBox(handle.input.spouseFirst),
                          ReadStringFromTextBox(handle.input.spouseLast),
                          ReadStringFromTextBox(handle.input.children),
                          ReadStringFromTextBox(handle.input.street),
                          ReadStringFromTextBox(handle.input.city),
                          ReadStringFromTextBox(handle.input.state),
                          ReadStringFromTextBox(handle.input.zip),
                          ReadStringFromTextBox(handle.input.inviteeType),
                          ReadStringFromTextBox(handle.input.eventState))) {
    return;
  }

  if (getHandle(invitee.group()) != -1) {
    AddLineToTextBox(invitee.group(), invitee.getAddress());
  }
}
