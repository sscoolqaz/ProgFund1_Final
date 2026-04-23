#pragma once
#include <string>
#include <vector>

struct InviteeParams {
  std::string iTitle = "";
  std::string iFirst = "";
  std::string iLast = ""; // required
  std::string iSuffix = "";
  std::string iSpouseTitle = "";
  std::string iSpouseFirst = "";
  std::string iSpouseLast = "";
  std::vector<std::string> iChildren = {};
  std::string iStreetAddress = ""; // required
  std::string iCity = "";          // required
  std::string iZipcode = "";       // required
  std::string iInviteeType = "";
  std::string iEventState = "";
};

class ParticipantClass {
private:
  InviteeParams data;

  bool verifyRequired(std::string last, std::string streetAddress,
                      std::string city, std::string zipcode) {
    if (last == "" || streetAddress == "" || city == "" || zipcode == "") {
      return false;
    }
    return true;
  }

  std::vector<std::string> verifyChildren(std::string children) {
    std::vector<std::string> realChildren = {};

    if (children == "") {
      realChildren.push_back("");
      return realChildren;
    }

    std::string childName;
    for (std::string::iterator iter = children.begin(); iter != children.end();
         ++iter) {
      if (*iter == ',') {
        realChildren.push_back(childName);
        childName = "";
        continue;
      }
      childName += *iter;
    }
    // remember to add the last name
    realChildren.push_back(childName);

    return realChildren;
  }

public:
  // initialize pointer to data type

  bool setInvitee(const std::string &uTitle, const std::string &uFirst,
                  const std::string &uLast, // required
                  const std::string &uSuffix, const std::string &uSpouseTitle,
                  const std::string &uSpouseFirst,
                  const std::string &uSpouseLast, const std::string &uChildren,
                  const std::string &uStreetAddress, // required
                  const std::string &uCity,          // required
                  const std::string &uZipcode,       // required
                  const std::string &uInviteeType,
                  const std::string &uEventState) {

    if (verifyRequired(uLast, uStreetAddress, uCity, uZipcode) != 0) {
      return false;
    }

    data.iTitle = uTitle;
    data.iFirst = uFirst;
    data.iLast = uLast;
    data.iSuffix = uSuffix;
    data.iSpouseTitle = uSpouseTitle;
    data.iSpouseFirst = uSpouseFirst;
    data.iSpouseLast = uSpouseLast;
    data.iChildren = verifyChildren(uChildren);
    data.iStreetAddress = uStreetAddress;
    data.iCity = uCity;
    data.iZipcode = uZipcode;
    data.iInviteeType = uInviteeType;
    data.iEventState = uEventState;

    return true;
  }
};
