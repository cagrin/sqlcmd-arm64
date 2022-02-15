# sqlcmd-arm64

This is "fake" version of ```sqlcmd```<sup>1</sup> utility for ARM64. It actually calls ```Invoke-SqlCmd```<sup>2</sup> from PowerShell with SqlServer module<sup>3</sup>. The use case of sqlcmd-arm64 is to be available inside ARM64 version of ```azure-sql-edge```<sup>4</sup> container, so that ```testcontainer```<sup>5</sup> can access it and use it to check whenever container is ready or not yet.

## References

<sup>1)</sup> https://docs.microsoft.com/en-us/sql/tools/sqlcmd-utility?view=sql-server-ver15

<sup>2)</sup> https://docs.microsoft.com/en-us/powershell/module/sqlserver/invoke-sqlcmd?view=sqlserver-ps

<sup>3)</sup> https://docs.microsoft.com/en-us/sql/powershell/download-sql-server-ps-module?view=sql-server-ver15

<sup>4)</sup> https://hub.docker.com/_/microsoft-azure-sql-edge

<sup>5)</sup> https://github.com/HofmeisterAn/dotnet-testcontainers