import os
import json
from banner import print_banner

File = "user_tasks.json"

def load_json_data():
    if not os.path.exists(File):
        return []
    with open(File, "r") as data:
        return json.load(data)

def save_json_data(data):
    with open(File, "w") as f:
        json.dump(data, f, indent=4)

def user_id_finder(user):
    data = load_json_data()
    for user_data in data:
        if user_data["user"] == user:
            return user_data["user_id"]
    return None

def user_name_finder(user_id):
    data = load_json_data()
    for user_data in data:
        if user_data["user_id"] == user_id:
            return user_data["user"]
    return None

def task_completion(user_id, task_id):
    data = load_json_data()
    for user in data:
        if user["user_id"] == user_id:
            for task in user["tasks"]:
                if task["task_id"] == task_id:
                    task["task_status"] = True
                    print(f"Marked task {task_id} as complete for {user['user']}")
                    save_json_data(data)
                    return
            print("Task not found.")
            return
    print("User not found.")

def print_tasks(user_id):
    data = load_json_data()
    print_banner(f"Tasks List for {user_name_finder(user_id)}")
    for user in data:
        if user["user_id"] == user_id:
            print(f"Tasks for {user['user']}:")
            if not user["tasks"]:
                print("No tasks found.")
            for i, task in enumerate(user["tasks"], start=1):
                status = "<*>" if task["task_status"] else "< >"
                print(f"{i}. Task ID: {task['task_id']}, Task: {task['task_objective']}, Status: {status}")
            return
    print("User not found.")

def logMenu():
    print_banner("Login Menu")
    print("1. Login to your account")
    print("2. Show Users")
    print("3. Add User")
    print("4. Exit")
    return input("Enter your choice: ").strip()

def menu():
    print_banner("To-Do Menu")
    print("1. Show Tasks")
    print("2. Add Task")
    print("3. Mark Task as Complete")
    print("4. Logout")
    return input("Enter your choice: ").strip()

def main():
    while True:
        choiceLog = logMenu()

        if choiceLog == "1":
            user = input("Enter your username: ").strip()
            user_id = user_id_finder(user)
            if user_id is None:
                print("User not found. Please register first.")
                continue

            while True:
                choiceUser = menu()
                if choiceUser == "1":
                    print_tasks(user_id)

                elif choiceUser == "2":
                    task_objective = input("Enter your task: ").strip()
                    data = load_json_data()
                    
                    for user in data:
                        if user["user_id"] == user_id:
                            print_banner("Add Task")
                            task_id_int = len(user["tasks"]) + 1
                            if( task_id_int < 10):
                                task_id = f"t00{task_id_int}"
                            elif( task_id_int < 100):
                                task_id = f"t0{task_id_int}"
                            else:
                                task_id = f"t{task_id_int}"
                            new_task = {
                                "task_id": task_id,
                                "task_objective": task_objective,
                                "task_status": False
                            }
                            user["tasks"].append(new_task)
                            save_json_data(data)
                            print(f"Task '{task_objective}' added with ID {task_id}")
                            break

                elif choiceUser == "3":
                    print_banner("Mark Task as Complete")
                    print("Here are your tasks:")
                    print_tasks(user_id)
                    task_id = input("Enter the Task ID to mark as complete: ")
                    task_completion(user_id, task_id)
                elif choiceUser == "4":
                    username = user_name_finder(user_id)
                    print_banner(f"Bye {username}!")
                    print("Exiting...")
                    break
                else:
                    print("Invalid choice. Please try again.")
                
        elif choiceLog == "2":
            data = load_json_data()
            print_banner("User List")
            for user in data:
                print(f"User: {user['user']}, User ID: {user['user_id']}")
        elif choiceLog == "3":
            print_banner("Add User")
            new_user = input("Enter new username: ")
            new_user_id = len(load_json_data()) + 1  
            new_user_data = {
                "user": new_user,
                "user_id": new_user_id,
                "tasks": []
            }
            data = load_json_data()
            data.append(new_user_data)
            save_json_data(data)
            print(f"User {new_user} added with User ID {new_user_id}.")
        elif choiceLog == "4":
            print_banner("Goodbye!")
            print("Exiting...")
            return
        else:
            print("Invalid choice. Please try again.")
            return


if __name__ == "__main__":
    main()
