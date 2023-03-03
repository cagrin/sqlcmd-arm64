## Build

```
cc darwin/src/sqlcmd.c -o darwin/build/sqlcmd
```

## Run

```
darwin/build/sqlcmd -a -b -c
```

## Install PowerShell with SqlServer module
```
curl -sSL -o /tmp/powershell.deb https://github.com/PowerShell/PowerShell/releases/download/v7.2.10/powershell-lts_7.2.10-1.deb_amd64.deb
sudo dpkg -i /tmp/powershell.deb
pwsh -Command Install-Module -Name SqlServer -RequiredVersion 21.1.18256 -AllowClobber -Force -Scope AllUsers
```