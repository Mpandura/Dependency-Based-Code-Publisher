#pragma once
/////////////////////////////////////////////////////////////////////
// HttpMessage.h - Build and parse Http style messages             //
//                                                                 //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2016       //
/////////////////////////////////////////////////////////////////////

#include <vector>
#include <string>
#include <array>
#include<unordered_map>

//commands
#define UPLOAD "00"
#define START_UPLOAD "01"
#define END_UPLOAD "02"
#define REQUEST_UPLOAD "04"
#define ACK_UPLOAD "05"

#define DOWNLOAD "11"
#define START_DOWNLOAD "12"
#define END_DOWNLOAD "13"
#define REQUEST_DOWNLOAD "14"
#define ACK_DOWNLOAD "15"

#define SEND_HTTPMESSAGE "21"
#define ACK_HTTPMESSAGE "22"

#define REQUEST_ALL_FILES "31"
#define RESPONSE_ALL_FILES "32"

#define END_CLIENT_RECEIVER "41"
#define END_SERVER "42"

//functions
#define SEND_MESSAGE "sendMessage"
#define UPLOAD_REQUEST "uploadRequest"
#define DOWNLOAD_REQUEST "downloadRequest"
#define UPLOAD_RESPONSE "uploadResponse"
#define DOWNLOAD_RESPONSE "downloadResponse"
#define GETALLFILES_REQUEST "reqgetallfiles"
#define GETALLFILES_RESPONSE "resgetallfiles"


#define BUFF_SIZE 1024
#define COMMAND "command"
#define TO_ADDR "to_Addr"
#define TO_PORT "to_Port"
#define FROM_ADDR "from_Addr"
#define FROM_PORT "from_Port"
#define FILENAME "fileName"
#define AUTHOR "author"
#define CON_LEN "contentLen"
#define BODY "body"
#define OPEN "open"
#define SEPARATOR '|'
#define FILES_SEP '^'
#define EOT 0x03

class HttpMessage
{
public:
  using byte = char;
  using Name = std::string;
  using Value = std::string;
  using Attribute = std::pair<Name, Value>;
  using Attributes = std::vector<Attribute>;
  using Terminator = std::string;
  using Body = std::vector<byte>;

  // message attributes
  void addAttribute(const Attribute& attrib);
  Value findValue(const Name& name);
  size_t findAttribute(const Name& name);
  bool removeAttribute(const Name& name);
  Attributes& attributes();
  static std::string attribString(const Attribute& attrib);
  static Attribute attribute(const Name& name, const Value& value);
  static Attribute parseAttribute(const std::string& src);

  // message body
  void setBody(byte buffer[], size_t Buflen);
  size_t getBody(byte buffer[], size_t& Buflen);
  void addBody(const Body& body);
  void addBody(const std::string& body);
  void addBody(size_t numBytes, byte* pBuffer);
  Body& body();
  std::string command;
  size_t bodyLength();
  static std::unordered_map<std::string, std::string> getAttributes(std::string msg);
  static HttpMessage parseStringMessage(std::string msg);
  // construct message
  //static HttpMessage parseHeader(const std::string& src);
  //static HttpMessage parseMessage(const std::string& src);
  static std::string createHTTPMessage(HttpMessage msg);
  // display
  std::string headerString() const;
  std::string bodyString() const;
  std::string toString() const;
  std::string toIndentedHeaderString() const;
  std::string toIndentedBodyString() const;
  std::string toIndentedString() const;
  std::string toAddr;
  int toPort;
  std::string fromAddr;
  int fromPort;
  std::string fileName;
  std::string author;
  std::string open;
  int contentLen = 0;
  // cleanup
  void clear();
  static void fillBuffer(byte buffer[], size_t BufSize, byte fill = '\0');

private:
  Attributes attributes_;
  Terminator term_ = "\n";
  Body body_;
};