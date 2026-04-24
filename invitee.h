#pragma once
#include <string>
#include <vector>

namespace inv {

class ParticipantClass {
private:
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
    std::string iState = "";
    std::string iZipcode = ""; // required
    std::string iInviteeType = "";
    std::string iEventState = "";
  };

  InviteeParams data;

  bool verifyRequired(std::string last, std::string streetAddress,
                      std::string city, std::string state,
                      std::string zipcode) {
    if (last.empty() || streetAddress.empty() || city.empty() ||
        state.empty() || zipcode.empty()) {
      return false;
    }
    return true;
  }

  std::vector<std::string> verifyChildren(std::string children) {
    std::vector<std::string> realChildren = {};

    // iterate through the string and build the childs name
    std::string childName;
    for (std::string::iterator iter = children.begin(); iter != children.end();
         ++iter) {
      // check for delimiter
      if (*iter == ',') {
        // check if the string is empty so we dont push bad data
        if (childName.empty()) {
          continue;
        }

        // adds child name to vector
        realChildren.push_back(childName);
        childName = "";
        continue;
      }

      // add the char to the string
      childName += *iter;
    }

    // remember to add the last name
    if (!childName.empty()) {
      realChildren.push_back(childName);
    }
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
                  const std::string &uState,         // required
                  const std::string &uZipcode,       // required
                  const std::string &uInviteeType,
                  const std::string &uEventState) {

    if (verifyRequired(uLast, uStreetAddress, uCity, uState, uZipcode)) {
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
    data.iState = uState;
    data.iZipcode = uZipcode;
    data.iInviteeType = uInviteeType;
    data.iEventState = uEventState;

    return true;
  }

  std::string getAddress() {
    int childCount = data.iChildren.size();

    std::string postage;

    if (data.iSpouseFirst.empty()) {
      postage = data.iTitle + " " + data.iFirst + " " + data.iLast;
      if (!data.iSuffix.empty())
        postage += " " + data.iSuffix;

    } else if (data.iLast == data.iSpouseLast) {
      postage = data.iSpouseTitle + " " + data.iSpouseFirst + " and " +
                data.iTitle + " " + data.iFirst + " " + data.iLast;

    } else {
      postage =
          data.iSpouseTitle + " " + data.iSpouseFirst + " " + data.iSpouseLast;
      if (!data.iSuffix.empty())
        postage += " " + data.iSuffix;

      postage += " and " + data.iTitle + " " + data.iFirst + " " + data.iLast;
      if (!data.iSuffix.empty())
        postage += " " + data.iSuffix;

      if (childCount == 1)
        postage += " and " + data.iChildren[0];
      else if (childCount >= 2)
        postage += " and Family";
    }

    if (childCount == 1)
      postage += " and " + data.iChildren[0];
    else if (childCount >= 2)
      postage += " and Family";

    postage += "\n" + data.iStreetAddress + "\n" + data.iCity + ", " +
               data.iState + ". " + data.iZipcode;

    return postage + "\n\n";
  }
};
} // namespace inv
