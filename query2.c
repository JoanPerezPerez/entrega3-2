#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main (int argc, char **argv)
{
	MYSQL*conn;
	MYSQL_RES *res;
	MYSQL_ROW row;
	int err;
	
	conn = mysql_init(NULL);
	if (conn==NULL){
		printf("Error al crear conexion:%u%s\n", mysql_errno(conn), mysql_error(conn));
		exit(1);
	}
	conn = mysql_real_connect(conn, "localhost", "root", "mysql", NULL, 0, NULL, 0);
	if (conn==NULL){
		printf("Error al inicializar la connexion:%u%s\n", mysql_errno(conn), mysql_error(conn));
		exit(1);
	}
	err = mysql_query (conn, "use proyecto;");
	err = mysql_query (conn, "SELECT ID FROM Partida WHERE winner = 'Joan';");
	res = mysql_store_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL){
		int ID = atoi (row [0]);
		char ID_str[20];
		sprintf(ID_str, "%d", ID);
		printf("ID como cadena. %s\n", ID_str);
	}
	mysql_free_result(res);
	mysql_close(conn);
}