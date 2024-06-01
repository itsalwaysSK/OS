import subprocess

def list_processes():
    print("Listing all running processes:")
    # Using subprocess to execute the 'ps' command
    result = subprocess.run(["ps", "aux"], capture_output=True, text=True)
    print(result.stdout)

def kill_process():
    pid = input("Enter the PID of the process to kill: ")
    # Using subprocess to execute the 'kill' command
    subprocess.run(["kill", pid])
    print("Process with PID", pid, "has been killed")

def main():
    while True:
        print("1. List all running processes")
        print("2. Kill a process")
        print("3. Exit")

        choice = input("Enter your choice: ")

        if choice == '1':
            list_processes()
        elif choice == '2':
            kill_process()
        elif choice == '3':
            break
        else:
            print("Invalid choice")

if __name__ == "__main__":
    main()
