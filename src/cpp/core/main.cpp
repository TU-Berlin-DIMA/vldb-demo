#include "core/constants.h"
#include "core/Frontend.h"

namespace Myriad {

/**
 * Application name.
 */
const String Constant::APP_NAME = "vldb-demo - Parallel Data Generator";

/**
 * Application version.
 */
const String Constant::APP_VERSION = "0.1.0";

} // Myriad namespace

// define the application main method
POCO_APP_MAIN(Myriad::Frontend)
