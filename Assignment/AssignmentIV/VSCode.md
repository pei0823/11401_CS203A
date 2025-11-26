# Connect to GitHub with VSCode
- 開發平台window
  

## Prerequisites
Before you begin, ensure you have the following:
- Visual Studio Code installed on your computer. [Download VS Code here](https://code.visualstudio.com/)
- Git installed and configured on your system. [Download Git here](https://git-scm.com/).
- A GitHub account.

## Steps to Connect to GitHub

1. **Install the GitHub Extension for VSCode**
    - Open VSCode.
    - Go to the Extensions view by clicking on the Extensions icon in the Activity Bar on the side of the window.
    - Search for "GitHub Pull Requests and Issues" and install the extension.
    - 已完成

2. **Sign in to GitHub**
    - Open the Command Palette )
    - Type `GitHub: Sign in` and select the option.
    - Follow the prompts to authenticate with your GitHub account.
    - 已完成

3. **Clone a Repository**
    - In VSCode, open the Command Palette.
    - Type `Git: Clone` and select the option.
    - Paste the URL of your GitHub repository when prompted.
    - Choose a local folder where the repository will be cloned.
    - 直接按上方搜尋框，打github 就會出來了 ，記得要先創一個本地端的資料夾。

4. **Open the Repository**
    - Once the repository is cloned, VSCode will prompt you to open it.
    - Click `Open` to start working on your project.

-這裡要先確認資料夾的分層，cd可以打開資料夾。

5. **Make Changes and Commit**
    - Edit files in the repository as needed.
    - Go to the Source Control view in VSCode.
    - Stage your changes, write a commit message, and commit the changes.
    - 需要先做變更才會出現

6. **Push Changes to GitHub**
    - After committing, click the `Sync Changes` button in the Source Control view.
    - This will push your changes to the GitHub repository.

## Additional Tips
- Use the built-in terminal in VSCode for advanced Git commands.
- Enable GitLens extension for enhanced Git insights.

By following these steps, you can easily connect and manage your GitHub repositories using Visual Studio Code.
