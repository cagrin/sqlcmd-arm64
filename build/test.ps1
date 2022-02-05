cmake ..
make
./sqlcmd -S localhost,51433 -U sa -P A.794613
./sqlcmd -b -r 1 -S localhost,51433 -U sa -P A.794613 -i script.sql

# docker run -e 'ACCEPT_EULA=1' -e 'MSSQL_SA_PASSWORD=A.794613' -p 51433:1433 -d mcr.microsoft.com/azure-sql-edge

<#
  # https://github.com/HofmeisterAn/dotnet-testcontainers/blob/develop/src/DotNet.Testcontainers/Configurations/Modules/Databases/MsSqlTestcontainerConfiguration.cs

  public override IWaitForContainerOS WaitStrategy => Wait.ForUnixContainer()
    .UntilCommandIsCompleted("/opt/mssql-tools/bin/sqlcmd", "-S", $"localhost,{this.DefaultPort}", "-U", this.Username, "-P", this.Password);
#>
<#
  # https://github.com/HofmeisterAn/dotnet-testcontainers/blob/develop/src/DotNet.Testcontainers/Containers/Modules/Databases/MsSqlTestcontainer.cs

  return await this.ExecAsync(new[] { "/opt/mssql-tools/bin/sqlcmd", "-b", "-r", "1", "-S", $"{this.Hostname},{this.ContainerPort}", "-U", this.Username, "-P", this.Password, "-i", tempScriptFile }, ct)
    .ConfigureAwait(false);
#>