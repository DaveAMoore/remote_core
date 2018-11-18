//
//  Error.h
//  remote_core
//
//  Created by David Moore on 11/18/18.
//  Copyright © 2018 David Moore. All rights reserved.
//

#ifndef Error_h
#define Error_h

namespace RemoteCore {
    enum class Error {
        None                        = 0,
        Unknown                     = -1,
        NoSignalWhileTraining       = -2,
    };
}

#endif /* Error_h */
