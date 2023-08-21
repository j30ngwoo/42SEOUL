# pipex: Implementation of bash redirection(>) and pipe(|)

### ✅ Details in: <a href="https://meadow-anchovy-6ba.notion.site/pipex-8ad93bd2ad0c4c5a8651b47e9d22b5aa?pvs=4"><img src="https://img.shields.io/badge/Notion-000000?style=flat-square&logo=Notion&logoColor=white&link=https://www.notion.so/2b896c0fcee14adb999bf86f3f274467"></a>

### Mandatory
- Implementation of one each <, >, |   
```$ < [infile] [cmd1] | [cmd2] > [outfile]```    

### Bonus Part
- Implementation a number of pipe( | )  
```$ < [infile] [cmd1] | [cmd2] | ... | [cmd] > [outfile]```
- Implementation of heredoc(<<) and append(>>)  
```$ << [DELIMITER] [cmd1] | [cmd2] | ... | [cmd] >> [outfile]```

### How to use
```make``` to mandatory part, ```make bonus``` to bonus part.  
#### - mandatory part
```bash
$ ./pipex [infile] [cmd1] [cmd2] [outfile]
```
🔺 behave like:  
```$ < [infile] [cmd1] | [cmd2]  [outfile]```  

#### - bonus part
```bash
$ ./pipex [infile] [cmd1] [cmd2] ... [cmd] [outfile]
```
🔺 behave like:  
```$ < [infile] [cmd1] | [cmd2] | ... | [cmd] > [outfile]```
```
$ ./pipex here_doc [delimiter] [cmd1] [cmd2] ... [cmd] [outfile]
```
🔺 behave like:  
```$ << [delimiter] [cmd1] | [cmd2] | ... | [cmd] >> [outfile]```
