#pragma once

#include <FS.h>
#include <SimpleFTPServer.h>

// Compatibility adapter for the legacy FTPServer API used by main.cpp.
// SimpleFTPServer selects LittleFS through the global PlatformIO build flags.
class FTPServer : public FtpServer {
public:
    explicit FTPServer(fs::FS &) : FtpServer() {}
};
