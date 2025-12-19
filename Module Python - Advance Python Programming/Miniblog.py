import tkinter as tk
from tkinter import messagebox
import os

class User:
    def __init__(self, name):
        self.name = name.strip()

class Post:
    def __init__(self, user, title, content):
        self.user = user
        self.title = title.strip()
        self.content = content.strip()

    def filename(self):
        safe_title = self.title.replace(" ", "_")
        safe_user = self.user.name.replace(" ", "_")
        return f"{safe_user}_{safe_title}.txt"

    def save(self):
        with open(self.filename(), "w", encoding="utf-8") as f:
            f.write(f"Author: {self.user.name}\n")
            f.write(f"Title: {self.title}\n\n")
            f.write(self.content)

    @staticmethod
    def load(filename):
        with open(filename, "r", encoding="utf-8") as f:
            return f.read()

class MiniBlogApp:
    def __init__(self, root):
        self.root = root
        self.root.title("MiniBlog")

        tk.Label(root, text="Username").grid(row=0, column=0)
        tk.Label(root, text="Title").grid(row=1, column=0)
        tk.Label(root, text="Content").grid(row=2, column=0)

        self.username_entry = tk.Entry(root, width=40)
        self.title_entry = tk.Entry(root, width=40)
        self.content_text = tk.Text(root, width=40, height=10)

        self.username_entry.grid(row=0, column=1)
        self.title_entry.grid(row=1, column=1)
        self.content_text.grid(row=2, column=1)

        tk.Button(root, text="Save Post", command=self.save_post).grid(row=3, column=1)
        tk.Button(root, text="Refresh Posts", command=self.load_posts).grid(row=4, column=1)

        self.post_list = tk.Listbox(root, width=40)
        self.post_list.grid(row=5, column=1)
        self.post_list.bind("<<ListboxSelect>>", self.view_post)

        self.load_posts()

    def save_post(self):
        username = self.username_entry.get()
        title = self.title_entry.get()
        content = self.content_text.get("1.0", tk.END)

        if not username or not title or not content.strip():
            messagebox.showerror("Error", "All fields are required.")
            return

        user = User(username)
        post = Post(user, title, content)

        try:
            post.save()
            messagebox.showinfo("Success", "Post saved successfully.")
            self.load_posts()
        except Exception as e:
            messagebox.showerror("Error", str(e))

    def load_posts(self):
        self.post_list.delete(0, tk.END)
        for file in os.listdir():
            if file.endswith(".txt"):
                self.post_list.insert(tk.END, file)

    def view_post(self, event):
        try:
            index = self.post_list.curselection()[0]
            filename = self.post_list.get(index)
            content = Post.load(filename)
            self.content_text.delete("1.0", tk.END)
            self.content_text.insert(tk.END, content)
        except IndexError:
            pass
        except FileNotFoundError:
            messagebox.showerror("Error", "File not found.")

root = tk.Tk()
app = MiniBlogApp(root)
root.mainloop()
