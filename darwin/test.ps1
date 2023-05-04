docker container stop test_image
docker container rm test_image
docker run --name test_image -e 'ACCEPT_EULA=1' -e 'MSSQL_SA_PASSWORD=A.794613' -p 51433:1433 -d mcr.microsoft.com/azure-sql-edge
Start-Sleep -Second 30

./build/sqlcmd -C -S localhost,51433 -d master -U sa -P A.794613

<#
  # https://github.com/testcontainers/testcontainers-dotnet/blob/develop/src/Testcontainers.MsSql/MsSqlContainer.cs

  return await ExecAsync(new[] { "/opt/mssql-tools/bin/sqlcmd", "-b", "-r", "1", "-U", _configuration.Username, "-P", _configuration.Password, "-i", scriptFilePath }, ct)
      .ConfigureAwait(false);

  # Failed without -C

  ./build/sqlcmd -b -r 1 -S localhost,51433 -U sa -P A.794613 -i test/script.sql
#>