
async_inti
async_deinit
async_callback
async_commit

协程解决:
dns_async_client_commit(struct async_context* ctx,const char *domain,async_result_cb cb)

1.建立sock  2.做好链接   3.准备好dns协议 4.send 5.io加入到epoll