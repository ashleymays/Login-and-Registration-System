# Login and Registration System
A login and registration comsole application made with C++20.



## Table of Contents
  * [Project Description](#project-description)
  * [How to Install and Run](#how-to-install-and-run)
  * [How to Use the Project](#how-to-use-the-project)
  * [Credits](#credits)
  * [Special Thanks](#special-thanks)
  * [License](#license)


## Project Description
A login and registration system that allows a user to create a new profile, complete with a username and password. The user can then read their profile, change their password, or delete it. The user profile will exist even after the project is closed, making it possible to login at a later date. The program was created entirely in C++ using the latest standards.

I initially wrote this program because of an [article that listed the best C++ projects](https://hackr.io/blog/cpp-projects). I know, it’s pretty uninspiring. Later on, though, it became more of a passion project as I encountered several obstacles that taught me various aspects of the C++ language. During the course of this (estimated) two-week long project, I learned about the filesystem library, directories and paths, linkers, and exceptions. I also gained a deeper understanding of the fstream library and good programming practices.

Later on, I hope to implement a way to keep track of the time and date a user last logged into their profile.



## How to Install and Run
### Clone the Repository
Go to the top left corner and click "Fork". This will create a copy of the repository in your Github account. Then navigate to the copied repository on your account titled YOUR_USERNAME/Login-and-Registration-System, where YOUR_USERNAME is your Github username. Click the "Code" button on the main page of the repository. Copy the link under "Clone with HTTPS". Open Git Bash on your desktop. Change the directory shown on the screen in Git Bash to the folder where you want the project to be. Then type ```git clone``` and paste the link to Git Bash. Press "Enter" to create the clone. For more information, <a href="https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository">consult the Github documentation.</a>

## How to Use the Project
When the program is run, the main menu will appear in the console. 

<img width="490" src="https://drive.google.com/uc?id=1EYTSyBGzgcnHRaud7rnklqxMHM97qwJj" />

Enter a number 1-3 to either (1) login to an existing account, (2) create a new profile, or (3) exit the program. Enter in the required credentials as they show up in the console. 

<img width="490" src="https://drive.google.com/uc?id=1FXo1YzT6wo5jIiXBx-NW24Po-MnB3S22" />

<img width="490" src="https://drive.google.com/uc?id=13M2qeQ8Nx9tnG37gXTI1A0b4z9jmBZw6" />

After logging in/signing up, the account options will appear in the console. Enter a number 1-4 to either (1) Read the information in your profile, (2) reset your password, (3) delete your account, or (4) sign out of your account.

<img width="490" src="https://drive.google.com/uc?id=1gzs-DHjlpdz3X7DEnx9RskbzgbQ1PAU4" />

Now, when you select "Read User Profile", it will show the following information.

<img width="490" src="https://drive.google.com/uc?id=1QRQ2XSm2nowh8WKhyCAMw285aJJS7tWE" />

When you create a profile, it will appear in the folder “Login and Registration System” as a text file titled “User_your_username_here”, where “your_username_here” is the username for the account.


## Credits
Credit to [Stack Overflow user Chris](https://stackoverflow.com/users/962089/chris) contributed the following lines as part of an answer to a question on Stack Overflow. They appear twice in the project: in the main() function and the accountOptions() method.

```C++
std::cin.clear();
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
```

## Special Thanks
Special thanks to [Hillary Nyakundi](https://github.com/larymak), whose [article](https://www.freecodecamp.org/news/how-to-write-a-good-readme-file/) helped me write this readme, [this website]("https://desktop.arcgis.com/en/arcmap/10.3/tools/supplement/pathnames-explained-absolute-relative-unc-and-url.htm") that taught me about directories and paths, and to the folks at Stack Overflow that taught me about the fstream library, file system library, and Github Markdown.


## License
This project is covered under the MIT License.
