# resource-monitor

A minimalist CLI tool to monitor system resource usage on UNIX-based systems.

## Features

- Real-Time Monitoring
    - Displays CPU and memory-usage in real-time, with support for visualisation.
- Logging
    - Logs resource usage information to a log file in a customizable format(JSON or CSV).
- Detailed Process Statistics
    - Displays the top 10 processes consuming the most resources.
    - Can monitor specific processes using their PIDs.

## Setup and Installation

- Prerequisites
    - GCC
- Clone the Repository
```bash
git clone https://github.com/lokeshllkumar/reosurce-monitor
cd resource-manager
```
- Build the Project
```bash
make
```
- Run the App
```bash
./resource-mananger
```

## Usage

- Supported options
    - ```--help``` or ```-h``` - displays the help menu
    - ```--real-time``` - shows system resource usage in real-time
    - ```--log``` - logs resource usage to a log file
    - ```--detailed``` - displays detailed process statistics
    - ```--pid <PID>``` - monitor a specific process identified by its process ID
- Configuration
    - The ```config/monior.conf``` file enables users to specify bar length and and the log file format.
