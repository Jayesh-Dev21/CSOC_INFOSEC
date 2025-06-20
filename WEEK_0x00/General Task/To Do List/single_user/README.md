# Build Instructions

## Requirements
Before you begin, ensure you have the following installed:
- Python 3.7 or higher
- pip (Python's package manager)

---

## Setting Up a Virtual Environment
It is recommended to use a virtual environment to isolate your dependencies and avoid conflicts with global Python installations.

1. Create a virtual environment:
   ```bash
   python -m venv venv
   ```

2. Activate the virtual environment:
   - On macOS/Linux:
     ```bash
     source venv/bin/activate
     ```
   - On Windows:
     ```cmd
     venv\Scripts\activate
     ```

3. Once activated, you will see `(venv)` in your terminal prompt.

4. Install the required dependencies:
   ```bash
   pip install -r requirements.txt
   ```

5. To deactivate the virtual environment when done:
   ```bash
   deactivate
   ```

---

To compile the app, simply run:
```bash
 
> make
 
```
This will execute the default target in the Makefile and build the application.


```bash
.
├── app                      # Compiled output (after running `make`)
├── main.c                   # Entry point for the C application
├── Makefile                 # Build script for compiling the C components
├── python_scripts/          # Python utility scripts
│   └── banner.py            # Generates banner (possibly CLI decoration or UI)
├── requirements.txt         # Python dependencies
├── src/                     # Source files and headers for core functionality
│   ├── headers/
│   │   ├── task_handler.h   # Header for task handling logic
│   │   └── utlis.h          # Header for utility functions (note: consider renaming to utils.h)
│   ├── task_handler.c       # Implements task handling logic
│   └── utils.c              # Implements utility/helper functions
└── user_tasks.txt           # Example user input or task definitions

```
