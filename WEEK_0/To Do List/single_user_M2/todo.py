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

def user_id_finder():
    return 0

def user_name_finder(user_id):
    data = load_json_data()
    for user_data in data:
        if user_data["user_id"] == user_id:
            return user_data["user"]
    return None

def task_completion(task_id):
    data = load_json_data()
    for user in data:
        if user["user_id"] == 0:
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
    print_banner(f"Tasks List for {user_name_finder(0)}")
    for user in data:
        if user["user_id"] == 0:
            print(f"Tasks for {user['user']}:")
            if not user["tasks"]:
                print("No tasks found.")
            for i, task in enumerate(user["tasks"], start=1):
                status = "<*>" if task["task_status"] else "< >"
                print(f"{i}. Task ID: {task['task_id']}, Task: {task['task_objective']}, Status: {status}")
            return
    print("User not found.")

def logMenu():
    print_banner("Hello! user!")
    print("1. Register")
    print("2. Exit")
    return input("Enter your choice: ").strip()

def menu():
    print_banner("To-Do Menu")
    print("1. Show Tasks")
    print("2. Add Task")
    print("3. Mark Task as Complete")
    print("4. Delete Task")
    print("5. Logout")
    print("6. Delete Account")
    return input("Enter your choice: ").strip()

def delete_account():
    data = load_json_data()
    for i, user in enumerate(data):
        if user["user_id"] == 0:
            username = user["user"]
            confirm = input(f"Are you sure you want to delete the account '{username}'? (yes/no): ").strip().lower()
            if confirm == "yes":
                data.pop(i)
                save_json_data(data)
                print_banner("Account Deleted")
                print(f"User '{username}' has been deleted along with all their tasks.")
                print_banner("Goodbye!")
                print("Thank you for using the To-Do App!")
                return True  
            else:
                print("Account deletion cancelled.")
                return False
    print("User not found.")
    return False

def delete_task(task_id):
    data = load_json_data()
    for user in data:
        if user["user_id"] == 0:
            for i, task in enumerate(user["tasks"]):
                if task["task_id"] == task_id:
                    deleted_task = user["tasks"].pop(i)
                    save_json_data(data)
                    print_banner("Task Deleted")
                    print(f"Deleted Task ID: {deleted_task['task_id']} - {deleted_task['task_objective']}")
                    return
            print("Task not found.")
            return
    print("User not found.")



def main():
    a = 0
    data = load_json_data()
    for user in data:
        a += 1
    if a == 0:
        choiceLog = logMenu()
        if choiceLog == "1":
            print_banner("Register")
            new_user = input("Enter new username: ")
            new_user_id = 0
            new_user_data = {
                "user": new_user,
                "user_id": new_user_id,
                "tasks": []
            }
            data = load_json_data()
            data.append(new_user_data)
            save_json_data(data)
            print(f"User {new_user} registered.")
        elif choiceUser == "2":
            username = user_name_finder(0)
            print_banner(f"Bye {username}!")
            print("Exiting...")
            print_banner("Goodbye!")
            print("Thank you for using the To-Do App!")
            return
        else:
            print("Invalid choice. Please try again.")
    print(f"Welcome! {user_name_finder(0)}")
    while True:
        choiceUser = menu()    
        
           
                
        if choiceUser == "1":
            print_tasks(0)

        elif choiceUser == "2":
            task_objective = input("Enter your task: ").strip()
            data = load_json_data()
            
            for user in data:
                if user["user_id"] == 0:
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
            print_tasks(0)
            task_id = input("Enter the Task ID to mark as complete: ")
            task_completion(task_id)
        elif choiceUser == "4":
            print_banner("Delete Task")
            print("Here are your tasks:")
            print_tasks(0)
            task_id = input("Enter the Task ID to delete: ").strip()
            delete_task(task_id)
        elif choiceUser == "5":
            username = user_name_finder(0)
            print_banner(f"Bye {username}!")
            print("Exiting...")
            print_banner("Goodbye!")
            print("Thank you for using the To-Do App!")
            return
        elif choiceUser == "6":
            delete_account()
            return
        else:
            print("Invalid choice. Please try again.")        
                
        

if __name__ == "__main__":
    main()
