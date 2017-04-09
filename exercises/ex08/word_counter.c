
#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <string.h>

void iterator(gpointer key, gpointer value, gpointer user_data) {
	printf(user_data, key, value);
}

int main(int argc, char** argv) {
	char str[100];
	GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);
	
	while(scanf("%s", str) != EOF) {
		printf("%s\n",str);
		// pch = strtok (str," ");
		// printf("%c",pch);
		if(g_hash_table_lookup(hash, str) == NULL) {
			g_hash_table_insert(hash, strdup(str), 1);
			// printf("%s",str);
		}
		else {
			g_hash_table_insert(hash, strdup(str), g_hash_table_lookup(hash, str) + 1);
			// printf("%s",str);
		}

			
	}
	g_hash_table_foreach(hash, (GHFunc)iterator, "%s appears %d times\n");
}