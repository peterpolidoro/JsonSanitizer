#include "Arduino.h"
#include "Streaming.h"
#include "JsonSanitizer.h"


const unsigned int BAUDRATE = 9600;
char json_valid[] = "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]}";
char json_partial_valid[] = "{\"sensor\":gps,test:null,truth:true,method:?,\"time\":1351824120,\"data\":[48.756080,2.302038]}";
char json_unsanitized_array[] = "  ? test, 1  ??   null true [1,2 3] \"nice string\" weird_\\\"string";
char json_unsanitized_object[] = "  server : example.com, post: 80, message: \"hello world\"";
char json_valid_request[] = "[\"setSerialNumber\",\"serial_number\",\"?\"]";
const unsigned int BUFFER_SIZE = 257;
char buffer[BUFFER_SIZE];
const unsigned int TOKEN_COUNT = 32;

void setup()
{
  Serial.begin(BAUDRATE);
}


void loop()
{
  JsonSanitizer sanitizer(TOKEN_COUNT);

  Serial << "json_valid: " << endl;
  Serial << json_valid << endl;
  strcpy(buffer,json_valid);
  sanitizer.sanitize(buffer,BUFFER_SIZE);
  Serial << "sanitized: " << endl;
  Serial << buffer << endl;
  Serial << endl;
  delay(1000);

  Serial << "json_partial_valid: " << endl;
  Serial << json_partial_valid << endl;
  strcpy(buffer,json_partial_valid);
  sanitizer.sanitize(buffer,BUFFER_SIZE);
  Serial << "sanitized: " << endl;
  Serial << buffer << endl;
  Serial << endl;
  delay(1000);

  Serial << "json_unsanitized_array: " << endl;
  Serial << json_unsanitized_array << endl;
  strcpy(buffer,json_unsanitized_array);
  sanitizer.sanitize(buffer,BUFFER_SIZE);
  Serial << "sanitized: " << endl;
  Serial << buffer << endl;
  Serial << endl;
  delay(1000);

  Serial << "json_unsanitized_object: " << endl;
  Serial << json_unsanitized_object << endl;
  strcpy(buffer,json_unsanitized_object);
  sanitizer.sanitize(buffer,BUFFER_SIZE);
  Serial << "sanitized: " << endl;
  Serial << buffer << endl;
  Serial << endl;
  delay(1000);

  Serial << "json_valid_request: " << endl;
  Serial << json_valid_request << endl;
  strcpy(buffer,json_valid_request);
  sanitizer.sanitize(buffer,BUFFER_SIZE);
  Serial << "sanitized: " << endl;
  Serial << buffer << endl;
  Serial << endl;
  delay(1000);
}