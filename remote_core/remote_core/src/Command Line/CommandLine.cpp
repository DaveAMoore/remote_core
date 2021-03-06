//
//  CommandLine.cpp
//  remote_core
//
//  Created by David Moore on 11/20/18.
//  Copyright © 2018 David Moore. All rights reserved.
//

#include "CommandLine.hpp"
#include <atomic>
#include <array>
#include <unistd.h>

using namespace RemoteCore;

CommandLine::CommandLine() {
    queue = std::make_unique<DispatchQueue>("ca.mooredev.remote_core.CommandLine.serial_dispatch_queue", 1);
}

std::shared_ptr<CommandLine> CommandLine::sharedCommandLine() {
    static std::shared_ptr<CommandLine> commandLine = nullptr;
    static std::atomic_bool once(false);
    
    if (!once) {
        once = true;
        commandLine = std::make_shared<CommandLine>();
    }
    
    return commandLine;
}

void CommandLine::executeCommandWithResultHandler(const char *command, std::function<void (std::string, bool)> resultHandler) {
    system(command);
    
    /*execl("/bin/sh", "sh", "-c", command);*/
    resultHandler("", true);
    
    //queue->execute([command, resultHandler]() {
        
        
        /*
        std::array<char, 128> buffer;
        std::string result;
        std::shared_ptr<FILE> pipe(popen(command, "r"), pclose);
        
        if (pipe == nullptr) {
            resultHandler(result, true);
        } else {
            while (feof(pipe.get()) == 0) {
                if (fgets(buffer.data(), 128, pipe.get()) != nullptr) {
                    if (result.length() > 1024) {
                        result = std::string(buffer.data());
                    } else {
                        result += buffer.data();
                    }
                    
                    resultHandler(result, false);
                }
            }
        }
        
        resultHandler(result, true);*/
    /*});*/
}
